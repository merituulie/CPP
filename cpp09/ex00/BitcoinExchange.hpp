
#pragma once

#include <iostream>
#include <fstream>
#include <map>
#include <cstdlib>

#define DATABASE_FILE "data.csv"

class BitcoinExchange
{
	private:
		typedef typename std::map<std::string, double> map;
		typedef typename std::pair<std::string, double> pair;
		map rates;

		BitcoinExchange(const BitcoinExchange& rhs);

		BitcoinExchange& operator=(const BitcoinExchange& rhs);

		void openFile(const char *input_file, std::ifstream& infile);
		void parseRates();

	public:
		~BitcoinExchange(void);
		BitcoinExchange(void);

		class UnableToOpenFileException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class InvalidDoubleCastException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class MapException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		void	printRates(const char *input_file);
};
