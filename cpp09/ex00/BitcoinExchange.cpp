#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& rhs)
{
	if (this == &rhs)
		std::cerr << "The instance to be copied is the instance itself\n";
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs)
{
	if (this != &rhs)
		return *this;
	return *this;
}

BitcoinExchange::~BitcoinExchange(void)
{
}

void BitcoinExchange::openFile(std::string& input_file, std::ifstream& infile)
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
		throw BitcoinExchange::InvalidDoubleCastException();

	return d;
}

void BitcoinExchange::parseRates(std::ifstream& infile)
{
	std::string line;
	do
	{
		getline(infile, line);
		if (line.empty() && !infile.eof())
			continue;
		int pos = line.find(',');
		std::string key = line.substr(0, pos);
		double value = convertToDouble(line.substr(pos + 1, line.length() - pos).c_str());
		rates[key] = value;
	} while (!infile.eof())
}

void BitcoinExchange::printRates(std::string& input_file)
{
	std::ifstream	infile;
	openFile(std::string("data.csv"), infile);
	parseRates(infile);
	infile.close();
}

const char *BitcoinExchange::UnableToOpenFileException::what() throw()
{
	return "Error when opening the file";
}

const char *BitcoinExchange::UnableToOpenFileException::what() const throw()
{
	return "Invalid double cast";
}
