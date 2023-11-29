
#include <iostream>
#include "iter.hpp"

void test_string()
{
	std::cout << "---- TEST STRING ----" << std::endl;
	std::string array[] = { "hello", "there", "how", "are", "you", "\n", "!" };
	size_t size = sizeof(array) / sizeof(std::string);

	std::cout << "Calling template function with printing function..." << std::endl;
	std::cout << "---------------------" << std::endl;
	iter<std::string>(array, size, printNode<std::string>);
	std::cout << "---------------------" << std::endl;

	std::cout << "\033[32mTEST OKAY\033[0m" << std::endl;
	std::cout << "---------------------" << std::endl;
}
