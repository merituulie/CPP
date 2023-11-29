
#include <iostream>
#include "Array.hpp"

void test_size()
{
	unsigned int size = 10;

	std::cout << "---- TEST SIZE ----" << std::endl;
	std::cout << "Initializing float array with " << size << " elements..." << std::endl;
	Array<float> elements(size);
	std::cout << "--------------------" << std::endl;
	std::cout << "Testing initial size..." << std::endl;
	if (elements.size() != size)
		std::cout << "\033[33mTEST FAIL\033[0m" << std::endl;
	else
		std::cout << "\033[32mTEST OKAY\033[0m" << std::endl;
	std::cout << "--------------------" << std::endl;
	std::cout << "Testing size after copy initialization..." << std::endl;
	Array<float> elements2(elements);
	if (elements2.size() != elements.size())
		std::cout << "\033[33mTEST FAIL\033[0m" << std::endl;
	else
		std::cout << "\033[32mTEST OKAY\033[0m" << std::endl;
	std::cout << "--------------------" << std::endl;
	std::cout << "Testing size after = operator..." << std::endl;
	Array<float> elements3(size + 1);
	elements3 = elements;
	if (elements3.size() != elements.size() || elements3.size() == size + 1)
		std::cout << "\033[33mTEST FAIL\033[0m" << std::endl;
	else
		std::cout << "\033[32mTEST OKAY\033[0m" << std::endl;
	std::cout << "--------------------" << std::endl;
}
