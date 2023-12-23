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

BitcoinExchange::~BitcoinExchange(void)
{
	rates.clear();
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
		{
			std::cout << scalar << std::endl;
			throw BitcoinExchange::InvalidFloatCastException();
		}

	return static_cast<float>(temp);
}

void BitcoinExchange::parse(
	map *mapToParse,
	const char *filename,
	const char *delimiter,
	float max,
	float min)
{
	std::ifstream	infile;
	openFile(filename, infile);
	std::string line;

	getline(infile, line);
	while (!infile.eof())
	{
		getline(infile, line);
		if (infile.eof())
			break;
		if (line.empty() && !infile.eof())
			continue;

		size_t pos = line.find(delimiter);
		if (pos == std::string::npos)
			throw BitcoinExchange::FileInvalidException();
		std::string key = line.substr(0, pos);
		float value = convertToFloat(line.substr(pos + std::string(delimiter).length(), line.length() - pos).c_str(), max, min);

		std::pair<map::iterator,bool> result;
		result = mapToParse->insert(pair(key, value));
		if (!result.second)
		{
			std::cout << key << std::endl;
			std::cout << value << std::endl;
			infile.close();
			throw BitcoinExchange::MapException();
		}
	}

	infile.close();
}

void BitcoinExchange::printRates(const char *input_file)
{
	parse(&rates, DATABASE_FILE, ",", limits::max(), limits::max());
	parse(&stocks, input_file, " | ", 1000.0, 0.0);
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
