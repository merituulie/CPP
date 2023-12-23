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

static double	convertToDouble(const char *scalar)
{
	char *endptr;
	double d = std::strtod(scalar, &endptr);

	if (*endptr != '\0')
	{
		std::cout << "failed to convert '" << scalar << "' into " << d << "\n";
		throw BitcoinExchange::InvalidDoubleCastException();
	}

	return d;
}

void BitcoinExchange::parseRates()
{
	std::ifstream	infile;
	openFile(DATABASE_FILE, infile);
	std::string line;

	getline(infile, line);
	while (!infile.eof())
	{
		getline(infile, line);
		if (line.empty() && !infile.eof())
			continue;

		int pos = line.find(',');
		std::string key = line.substr(0, pos);
		double value = convertToDouble(line.substr(pos + 1, line.length() - pos).c_str());

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

void BitcoinExchange::printRates(const char *input_file)
{
	parseRates();

}

const char *BitcoinExchange::UnableToOpenFileException::what() const throw()
{
	return "Opening a file failed";
}

const char *BitcoinExchange::InvalidDoubleCastException::what() const throw()
{
	return "Invalid double cast";
}

const char *BitcoinExchange::MapException::what() const throw()
{
	return "Inserting value to a map failed";
}
