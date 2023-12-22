
#pragma once

#include <iostream>
#include <fstream>
#include <map>

class BitcoinExchange
{
	private:
		std::map<std::string, double> rates;

		BitcoinExchange(const BitcoinExchange& rhs);
		~BitcoinExchange(void);

		BitcoinExchange& operator=(const BitcoinExchange& rhs);

		void openFile(std::string& input_file, std::ifstream& infile);
		void parseRates(std::ifstream& infile);

	public:
		BitcoinExchange(void);

		class UnableToOpenFileException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class InvalidDoubleCastException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		void	printRates(std::string input_file);
};
