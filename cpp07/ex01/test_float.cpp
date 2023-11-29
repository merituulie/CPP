
#include <iostream>
#include "iter.hpp"

void test_float()
{
	std::cout << "---- TEST FLOAT ----" << std::endl;
	float array[] = { 1.1f, 2.3f, 3.5f, 4.8f, 5.9f };
	size_t size = sizeof(array) / sizeof(float);

	std::cout << "Calling template function with printing function..." << std::endl;
	std::cout << "------------------" << std::endl;
	iter<float>(array, size, printNode<float>);
	std::cout << "------------------" << std::endl;

	std::cout << "\033[32mTEST OKAY\033[0m" << std::endl;
	std::cout << "--------------------" << std::endl;
}
