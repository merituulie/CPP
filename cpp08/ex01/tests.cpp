
#include <iostream>

#include "Span.hpp"

void test_init()
{
	std::cout << "---- TEST INIT ----" << std::endl;
	std::cout << "Initializing Span..." << std::endl;
	Span sp = Span(4);
	if (sp.getMaxSize() != 4)
		std::cout << "\033[31mTEST FAIL\033[0m" << std::endl;
	else
		std::cout << "\033[32mTEST OKAY\033[0m" << std::endl;
	std::cout << "Copy constructing Span..." << std::endl;
	Span sp1 = Span(sp);
	if (sp1.getMaxSize() != 4)
		std::cout << "\033[31mTEST FAIL\033[0m" << std::endl;
	else
		std::cout << "\033[32mTEST OKAY\033[0m" << std::endl;
	std::cout << "--------------------" << std::endl;
	std::cout << "Copy operator - size must be equal..." << std::endl;

	sp.addNumber(1);
	sp.addNumber(3);
	sp.addNumber(4);
	sp.addNumber(5);

	Span sp2 = Span(10);
	sp2.addNumber(-1);
	sp2.addNumber(-1);
	sp2.addNumber(-1);
	sp2.addNumber(-1);
	sp2.addNumber(-1);
	sp2.addNumber(-1);
	sp2.addNumber(-1);
	sp2.addNumber(-1);
	sp2.addNumber(-1);
	sp2.addNumber(-1);

	sp2 = sp;
	if (sp2.getMaxSize() != 4 || sp2.getInts().size() != 4)
		std::cout << "\033[31mTEST FAIL\033[0m" << std::endl;
	else
		std::cout << "\033[32mTEST OKAY\033[0m" << std::endl;
	std::cout << "--------------------" << std::endl;
	std::cout << "Copy operator - values should be equal..." << std::endl;
	const std::list<int> ints = sp2.getInts();
	for (std::list<int>::const_iterator it = ints.begin(); it != ints.end(); it++)
	{
		if (*it == -1)
			std::cout << "\033[31mTEST FAIL\033[0m" << std::endl;
	}
	std::cout << "\033[32mTEST OKAY\033[0m" << std::endl;
	std::cout << "--------------------" << std::endl;
}

void test_small()
{
	std::cout << "---- TEST SMALL ----" << std::endl;
	std::cout << "Initializing Span..." << std::endl;
	Span sp = Span(4);
	int longestSpan1 = -30;
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
	}
	std::cout << "--------------------" << std::endl;
	std::cout << "Trying to add a new number to a full Span..." << std::endl;
	try
	{
		Span sp = Span(1);
		sp.addNumber(1);
		sp.shortestSpan();
	}
	catch (const Span::NotEnoughElementsException& e)
	{
		std::cout << "\033[32mTEST OKAY: \033[33m" << e.what() << "\033[0m" << std::endl;
	}
	std::cout << "--------------------" << std::endl;
	std::cout << "Trying to add a new number to a full Span..." << std::endl;
	try
	{
		Span sp = Span(1);
		sp.addNumber(1);
		sp.longestSpan();
	}
	catch (const Span::NotEnoughElementsException& e)
	{
		std::cout << "\033[32mTEST OKAY: \033[33m" << e.what() << "\033[0m" << std::endl;
		std::cout << "--------------------" << std::endl;
		return ;
	}
	std::cout << "\033[31mTEST FAIL\033[0m" << std::endl;
}

void test_int_values()
{
	std::cout << "---- TEST INT VALUES ----" << std::endl;
	std::cout << "Initializing Span..." << std::endl;
	Span sp = Span(5);
	int longestSpan1 = 3;
	int longestSpan2 = 3;
	int shortestSpan1 = 3;
	int shortestSpan2 = 3;
	sp.addNumber(longestSpan1);
	sp.addNumber(longestSpan2);
	sp.addNumber(shortestSpan1);
	sp.addNumber(shortestSpan2);

	{
		std::cout << "Finding shortest span from the list..." << std::endl;
		unsigned int shortest = sp.shortestSpan();
		if (shortest != 0)
			std::cout << "\033[31mTEST FAIL\033[0m" << std::endl;
		else
			std::cout << "\033[32mTEST OKAY\033[0m" << std::endl;
		std::cout << "--------------------" << std::endl;
		std::cout << "Finding longest span from the list..." << std::endl;
		unsigned int longest = sp.longestSpan();
		if (longest != 0)
			std::cout << "\033[31mTEST FAIL\033[0m" << std::endl;
		else
			std::cout << "\033[32mTEST OKAY\033[0m" << std::endl;
		std::cout << "--------------------" << std::endl;
	}
	{
		std::cout << "Finding shortest span with negative values..." << std::endl;
		sp.addNumber(-100);
		unsigned int shortest = sp.shortestSpan();
		if (shortest != 0)
			std::cout << "\033[31mTEST FAIL\033[0m" << std::endl;
		else
			std::cout << "\033[32mTEST OKAY\033[0m" << std::endl;
		std::cout << "--------------------" << std::endl;
		std::cout << "Finding longest span with negative values..." << std::endl;
		unsigned int longest = sp.longestSpan();
		if (longest != 103)
			std::cout << "\033[31mTEST FAIL\033[0m" << std::endl;
		else
			std::cout << "\033[32mTEST OKAY\033[0m" << std::endl;
		std::cout << "--------------------" << std::endl;
	}
	{
		Span sp = Span(5);
		int longestSpan1 = -500;
		int longestSpan2 = -400;
		int shortestSpan1 = -300;
		int shortestSpan2 = -200;
		sp.addNumber(longestSpan1);
		sp.addNumber(longestSpan2);
		sp.addNumber(shortestSpan1);
		sp.addNumber(shortestSpan2);

		std::cout << "Finding shortest span with negative values..." << std::endl;
		unsigned int shortest = sp.shortestSpan();
		if (shortest != 100)
			std::cout << "\033[31mTEST FAIL\033[0m" << std::endl;
		else
			std::cout << "\033[32mTEST OKAY\033[0m" << std::endl;
		std::cout << "--------------------" << std::endl;
		std::cout << "Finding longest span with negative values..." << std::endl;
		unsigned int longest = sp.longestSpan();
		if (longest != 300)
			std::cout << "\033[31mTEST FAIL\033[0m" << std::endl;
		else
			std::cout << "\033[32mTEST OKAY\033[0m" << std::endl;
		std::cout << "--------------------" << std::endl;
	}
}

void test_big_span()
{
	std::cout << "---- TEST BIG SPAN ----" << std::endl;
	Span span = Span(20000);
	for (size_t i = 0; i < span.getMaxSize(); i++)
		span.addNumber(i);
	std::cout << "Finding shortest span with big input..." << std::endl;
	unsigned int shortest = span.shortestSpan();
	if (shortest != 1)
		std::cout << "\033[31mTEST FAIL\033[0m" << std::endl;
	else
		std::cout << "\033[32mTEST OKAY\033[0m" << std::endl;
	std::cout << "--------------------" << std::endl;
	std::cout << "Finding longest span with big input..." << std::endl;
	unsigned int longest = span.longestSpan();
	if (longest != span.getMaxSize() - 1)
		std::cout << "\033[31mTEST FAIL\033[0m" << std::endl;
	else
		std::cout << "\033[32mTEST OKAY\033[0m" << std::endl;
	std::cout << "--------------------" << std::endl;
	std::cout << "Trying to add a new number to a full Span..." << std::endl;
	try
	{
		span.addNumber(4);
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
		span.addNumber(newInts.begin(), newInts.end());
	}
	catch (const Span::FullException& e)
	{
		std::cout << "\033[32mTEST OKAY: \033[33m" << e.what() << "\033[0m" << std::endl;
		std::cout << "--------------------" << std::endl;
		return ;
	}
	std::cout << "\033[31mTEST FAIL\033[0m" << std::endl;
}
