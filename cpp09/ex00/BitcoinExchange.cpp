#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& rhs)
{
	*this = rhs;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs)
{
	if (this != &rhs)
	{
		rates.clear();
		for (map::const_iterator it = rhs.rates.begin(); it != rhs.rates.end(); it++)
			rates.insert(pair(*it));
	}
	return *this;
}

void BitcoinExchange::clearStocks()
{
	for (l_map::iterator it = stocks.begin(); it != stocks.end(); it++)
		it->second.clear();
	stocks.clear();
}

BitcoinExchange::~BitcoinExchange(void)
{
	rates.clear();
	clearStocks();
}

void BitcoinExchange::openFile(const char *input_file, std::ifstream& infile)
{
	infile.open(input_file);
	if (infile.fail() || !infile.is_open() || !infile.good() || infile.peek() == EOF)
	{
		infile.close();
		throw BitcoinExchange::UnableToOpenFileException();
	}
}

static void convertToMinMaxString(float max, float min, std::string *sMax, std::string *sMin)
{
	std::ostringstream oss;
	oss << max;
	*sMax = oss.str();
	oss.clear();
	oss << min;
	sMin->append("-");
	sMin->append(oss.str());
	oss.clear();
}

static std::string convertToString(float value)
{
	std::ostringstream oss;
	oss << value;
	return oss.str();
}

static std::string zero = "0";

static bool	isValidInt(const std::string scalar, int min, int max)
{
	std::string toCheck = scalar;
	if (scalar.length() == 2 && zero.compare(scalar.substr(0, 1)) == 0)
		toCheck = scalar.substr(1, scalar.length() - 1);

	char *endptr;
	long long longValue = std::strtol(toCheck.c_str(), &endptr, 10);
	if (*endptr != '\0' || longValue > max || longValue < min)
		return false;

	return true;
}

static bool isDateValid(const std::string& date)
{
	time_t now = time(0);
	tm *ltm = localtime(&now);
	int yearNow = 1900 + ltm->tm_year;

	if (date.length() != 10)
		return false;
	if (!isValidInt(date.substr(0, 4), 1900, yearNow))
		return false;
	if (!isValidInt(date.substr(5, 2), 1, 12))
		return false;
	if (!isValidInt(date.substr(8, 2), 1, 31))
		return false;

	std::string dash = "-";
	if (dash.compare(date.substr(4, 1)) != 0)
		return false;
	if (dash.compare(date.substr(7, 1)) != 0)
		return false;

	return true;
}

BitcoinExchange::fe_pair	BitcoinExchange::convertToFloat(const char *scalar, float max, float min)
{
	char* endptr;
	double temp = std::strtod(scalar, &endptr);
	std::string scalarString(scalar);
	if (*endptr != '\0' && (*endptr != 'f' && *(endptr + 1) != '\0'))
		return fe_pair(std::pair<float, std::string>(-1, scalarString), INVALIDVALUE);
	float value = static_cast<float>(temp);

	std::string maxString;
	std::string minString;
	convertToMinMaxString(max, min, &maxString, &minString);
	if ((temp >= max && scalarString.compare(maxString) != 0)
		|| (temp <= -min && scalarString.compare(minString) != 0))
		return fe_pair(std::pair<float, std::string>(value, scalarString), OVERFLOW);

	return fe_pair(std::pair<float, std::string>(static_cast<float>(temp), scalarString), NONE);
}

void BitcoinExchange::parseRates(
	const char *filename,
	const char *delimiter)
{
	std::ifstream	infile;
	openFile(filename, infile);
	std::string line;

	getline(infile, line);
	while (getline(infile, line))
	{
		if (line.empty() && !infile.eof())
			continue;

		size_t pos = line.find(delimiter);
		std::string key = line.substr(0, pos);
		fe_pair value = convertToFloat(
			line.substr(pos + std::string(delimiter).length(), line.length() - pos).c_str(),
			std::numeric_limits<float>::max(),
			std::numeric_limits<float>::max()
		);

		if (value.second != NONE)
			throw BitcoinExchange::FileInvalidException();
		std::pair<map::iterator,bool> result;
		result = rates.insert(pair(key, value.first.first));
		if (!result.second)
		{
			infile.close();
			throw BitcoinExchange::MapException();
		}
	}

	infile.close();
}

void BitcoinExchange::tryParseInput(
	const char *filename,
	const char *delimiter)
{
	std::ifstream	infile;
	openFile(filename, infile);
	std::string line;

	getline(infile, line);
	if (line.compare("date | value") != 0)
		throw BitcoinExchange::FileInvalidException();
	while (getline(infile, line))
	{
		if (line.empty() && !infile.eof())
			continue;

		size_t pos = line.find(delimiter);
		if (pos == std::string::npos && pos == 0)
			throw BitcoinExchange::FileInvalidException();
		std::string key = line.substr(0, pos);
		if (key.empty())
			continue;

		fe_pair value = fe_pair(std::pair<float, std::string>(-1, "-1"), INVALIDKEY);
		if (isDateValid(key))
		{
			value = convertToFloat(
			line.substr(pos + std::string(delimiter).length(), line.length() - pos).c_str(),
			1000.0f,
			0.0f);
		}

		std::pair<l_map::iterator, bool> result;
		l_map::iterator it = stocks.find(key);
		if (it != stocks.end())
			it->second.push_back(value);
		else
		{
			result = stocks.insert(l_pair(key, std::list<fe_pair>(1, value)));
			if (!result.second)
				throw BitcoinExchange::MapException();
		}
	}

	infile.close();
}

float BitcoinExchange::getDateRate(l_pair stock)
{
	map::const_iterator it = rates.lower_bound(stock.first);
	if (it->first.compare(stock.first) != 0 && rates.begin()->first.compare(it->first) != 0)
		it--;
	return it->second;
}

void BitcoinExchange::printExchange(l_pair stock)
{
	std::list<fe_pair>::const_iterator it = stock.second.begin();
	if (it->second == INVALIDKEY || it->second == INVALIDVALUE)
	{
		std::cout << "Error: bad input => " << stock.first << std::endl;
		return;
	}

	float closestDateRate = getDateRate(stock);
	for (; it != stock.second.end(); it++)
	{
		std::string output;
		if (it->first.first < 0)
			output = "Error: Not a positive number.";
		else if (it->second == OVERFLOW)
			output = "Error: too large a number.";
		else
		{
			output = stock.first;
			output.append(" => ");
			output.append(it->first.second);
			output.append(" = ");
			output.append(convertToString(it->first.first *  closestDateRate));
		}
		std::cout << output << std::endl;
	}
}

void BitcoinExchange::printExchanges(const char *input_file)
{
	if (rates.empty())
		parseRates(DATABASE_FILE, ",");
	tryParseInput(input_file, " | ");

	for (l_map::const_iterator it = stocks.begin(); it != stocks.end(); it++)
	{
		printExchange(*it);
	}

	clearStocks();
}

const char *BitcoinExchange::UnableToOpenFileException::what() const throw()
{
	return "Opening a file failed";
}

const char *BitcoinExchange::InvalidFloatCastException::what() const throw()
{
	return "Invalid float cast";
}

const char *BitcoinExchange::MapException::what() const throw()
{
	return "Inserting value to a map failed";
}

const char *BitcoinExchange::FileInvalidException::what() const throw()
{
	return "File input could not be parsed";
}
