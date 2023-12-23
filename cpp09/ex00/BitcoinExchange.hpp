
#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <map>
#include <limits>
#include <cstdlib>

#define DATABASE_FILE "data.csv"

class BitcoinExchange
{
	private:
		typedef typename std::numeric_limits<float> limits;
		typedef typename std::map<std::string, float> map;
		typedef typename std::pair<std::string, float> pair;
		map rates;
		map stocks;

		BitcoinExchange(const BitcoinExchange& rhs);

		BitcoinExchange& operator=(const BitcoinExchange& rhs);

		void openFile(const char *input_file, std::ifstream& infile);
		void parse(map *mapToParse, const char *filename, const char *delimiter, float max, float min);

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

		void	printRates(const char *input_file);
};
