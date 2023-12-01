
#include <iostream>

#include "Span.hpp"

void test_small()
{
	std::cout << "---- TEST SMALL ----" << std::endl;
	std::cout << "Initializing Span..." << std::endl;
	Span sp = Span(4);
	int longestSpan1 = 3;
	int longestSpan2 = 17;
	int shortestSpan1 = 9;
	int shortestSpan2 = 11;

	if (sp.getMaxSize() != 4)
		std::cout << "\033[31mTEST FAIL\033[0m" << std::endl;
	else
		std::cout << "\033[32mTEST OKAY\033[0m" << std::endl;
	std::cout << "--------------------" << std::endl;

	sp.addNumber(longestSpan1);
	sp.addNumber(longestSpan2);
	sp.addNumber(shortestSpan1);
	sp.addNumber(shortestSpan2);

	std::cout << "Finding shortest span from the list..." << std::endl;
	unsigned int shortest = sp.shortestSpan();
	if (shortest != (unsigned int)(shortestSpan2 - shortestSpan1))
		std::cout << "\033[31mTEST FAIL\033[0m" << std::endl;
	else
		std::cout << "\033[32mTEST OKAY\033[0m" << std::endl;
	std::cout << "--------------------" << std::endl;
	std::cout << "Finding longest span from the list..." << std::endl;
	unsigned int longest = sp.longestSpan();
	if (longest != (unsigned int)(longestSpan2 - longestSpan1))
		std::cout << "\033[31mTEST FAIL\033[0m" << std::endl;
	else
		std::cout << "\033[32mTEST OKAY\033[0m" << std::endl;
	std::cout << "--------------------" << std::endl;

	std::cout << "Trying to add a new number to a full Span..." << std::endl;
	try
	{
		sp.addNumber(4);
	}
	catch (const Span::FullException& e)
	{
		std::cout << "\033[32mTEST OKAY: \033[33m" << e.what() << "\033[0m" << std::endl;
		std::cout << "--------------------" << std::endl;
	}
	std::cout << "Trying to add a span of new numbers to a full Span..." << std::endl;
	try
	{
		std::list<int> newInts;
		newInts.push_back(1);
		sp.addNumber(newInts.begin(), newInts.end());
	}
	catch (const Span::FullException& e)
	{
		if (sp.getInts().size() != 4)
			std::cout << "\033[31mTEST FAIL\033[0m" << std::endl;
		std::cout << "\033[32mTEST OKAY: \033[33m" << e.what() << "\033[0m" << std::endl;
		std::cout << "--------------------" << std::endl;
		return ;
	}
	std::cout << "\033[31mTEST FAIL\033[0m" << std::endl;
}
