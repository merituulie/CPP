
#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <map>
#include <list>
#include <limits>
#include <cstdlib>

#define DATABASE_FILE "data.csv"

class BitcoinExchange
{
	private:
		typedef typename std::pair<std::string, float> pair;
		typedef typename std::map<std::string, float> map;
		map rates;

		typedef typename std::pair<std::string, std::list<float> > l_pair;
		typedef typename std::map<std::string, std::list<float> > l_map;
		l_map stocks;

		BitcoinExchange(const BitcoinExchange& rhs);

		BitcoinExchange& operator=(const BitcoinExchange& rhs);

		void openFile(const char *input_file, std::ifstream& infile);
		void parseRates(const char *filename, const char *delimiter);
		void tryParseInput(const char *filename, const char *delimiter);
		void clearListMap();

	public:
		~BitcoinExchange(void);
		BitcoinExchange(void);

		class UnableToOpenFileException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class InvalidFloatCastException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class MapException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class FileInvalidException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class FloatOverflowException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		void	printRates(const char *input_file);
};
