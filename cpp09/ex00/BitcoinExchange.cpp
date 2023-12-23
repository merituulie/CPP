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

void BitcoinExchange::clearListMap()
{
	for (l_map::iterator it = stocks.begin(); it != stocks.end(); it++)
		it->second.clear();
}

BitcoinExchange::~BitcoinExchange(void)
{
	rates.clear();
	stocks.clear();
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

static float	convertToFloat(const char *scalar, float max, float min)
{
	std::ostringstream oss;
	oss << std::setprecision(2) << std::fixed << max;
	std::string maxFloatStr = oss.str();
	oss.clear();
	std::string minFloatStr;
	oss << std::setprecision(2) << std::fixed << min;
	minFloatStr.append("-");
	minFloatStr.append(oss.str());
	oss.clear();

	char* endptr;
	double temp = std::strtod(scalar, &endptr);
	std::string scalarString(scalar);

	if ((*endptr != '\0' && (*endptr != 'f' && *(endptr + 1) != '\0'))
		|| (temp >= max && scalarString.compare(maxFloatStr) != 0)
		|| (temp <= -max && scalarString.compare(minFloatStr) != 0))
			throw BitcoinExchange::InvalidFloatCastException();

	return static_cast<float>(temp);
}

void BitcoinExchange::parseRates(
	const char *filename,
	const char *delimiter,
	float max,
	float min)
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
		float value = convertToFloat(line.substr(pos + std::string(delimiter).length(), line.length() - pos).c_str(), max, min);

		std::pair<map::iterator,bool> result;
		result = rates.insert(pair(key, value));
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
	const char *delimiter,
	float max,
	float min)
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
		if (pos == std::string::npos && pos == 0)
			throw BitcoinExchange::FileInvalidException();
		std::string key = line.substr(0, pos);
		if (key.empty())
			continue;

		float value;
		try
		{
			value = convertToFloat(line.substr(pos + std::string(delimiter).length(), line.length() - pos).c_str(), max, min);
		}
		catch(const BitcoinExchange::InvalidFloatCastException& e)
		{
			value = std::numeric_limits<float>::quiet_NaN();
		}

		std::pair<l_map::iterator, bool> result;
		l_map::iterator it = stocks.find(key);
		if (it != stocks.end())
		{
			it->second.push_back(value);
		}
		else
		{
			result = stocks.insert(l_pair(key, std::list<float>(1, value)));
			if (!result.second)
			{
				infile.close();
				throw BitcoinExchange::MapException();
			}
		}
	}

	infile.close();
}

void BitcoinExchange::printRates(const char *input_file)
{
	if (rates.empty())
		parseRates(DATABASE_FILE, ",", limits::max(), limits::max());
	tryParseInput(input_file, " | ", 1000.0, 0.0);

	for (l_map::iterator it = stocks.begin(); it != stocks.end(); it++)
	{
		std::cout << it->first << std::endl;
		for (std::list<float>::iterator itl = it->second.begin(); itl != it->second.end(); itl++)
			std::cout << *itl << "," << std::flush;
		std::cout << std::endl;
	}

	clearListMap();
	stocks.clear();
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
