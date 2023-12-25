
#include <iostream>

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2 || !argv[1])
	{
		std::cerr << "Expecting one parameter as input\n";
		return 1;
	}

	try
	{
		BitcoinExchange exchanger;
		exchanger.printExchanges(argv[1]);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << "\n";
		return 1;
	}

	return 0;
}
