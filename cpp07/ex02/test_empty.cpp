
#include <iostream>
#include "Array.hpp"

void test_empty()
{
	std::cout << "---- TEST EMPTY ----" << std::endl;
	std::cout << "Initializing empty int array..." << std::endl;
	Array<int> empty;
	std::cout << "--------------------" << std::endl;
	if (empty.size() != 0)
		std::cout << "\033[33mTEST FAIL\033[0m" << std::endl;
	else
		std::cout << "\033[32mTEST OKAY\033[0m" << std::endl;
	std::cout << "--------------------" << std::endl;
}
