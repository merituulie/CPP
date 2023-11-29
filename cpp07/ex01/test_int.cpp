
#include <iostream>
#include "iter.hpp"

void test_int()
{
	std::cout << "---- TEST INT ----" << std::endl;
	int array[] = { 1, 2, 3, 4, 5 };
	size_t size = sizeof(array) / sizeof(int);

	std::cout << "Calling template function with printing function..." << std::endl;
	std::cout << "------------------" << std::endl;
	iter<int>(array, size, printNode<int>);
	std::cout << "------------------" << std::endl;

	std::cout << "\033[32mTEST OKAY\033[0m" << std::endl;
	std::cout << "------------------" << std::endl;
}
