
#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <map>
#include <list>
#include <limits>
#include <cfloat>
#include <cstdlib>
#include <ctime>
#include <algorithm>

#define DATABASE_FILE "data.csv"

class BitcoinExchange
{
	private:
		typedef std::pair<std::string, float> pair;
		typedef std::map<std::string, float> map;
		map rates;

		std::string maxFloatStr;
		std::string minFloatStr;

		enum ERRORNUM
		{
			NONE,
			OVERFLOW,
			INVALIDVALUE,
			INVALIDKEY
		};

		typedef std::pair<std::pair<float, std::string>, ERRORNUM> fe_pair;
		typedef std::pair<std::string, std::list<fe_pair> > l_pair;
		typedef std::map<std::string, std::list<fe_pair> > l_map;
		l_map stocks;

		BitcoinExchange(const BitcoinExchange& rhs);

		BitcoinExchange& operator=(const BitcoinExchange& rhs);

		void printExchange(l_pair stock);
		float getDateRate(l_pair stock);
		void openFile(const char *input_file, std::ifstream& infile);
		void parseRates(const char *filename, const char *delimiter);
		void tryParseInput(const char *filename, const char *delimiter);
		fe_pair	convertToFloat(const char *scalar, float max, float min);
		void clearStocks();

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

		void	printExchanges(const char *input_file);
};
