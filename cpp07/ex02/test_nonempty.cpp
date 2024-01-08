
#include <iostream>
#include "Array.hpp"

void test_nonempty()
{
	unsigned int size = 5;

	std::cout << "---- TEST NONEMPTY ----" << std::endl;
	std::cout << "Initializing string array with " << size << " elements..." << std::endl;
	Array<std::string> elements(size);
	elements[0] = "hello";
	elements[1] = "how";
	elements[2] = "are";
	elements[3] = "ya";
	elements[4] = "?";

	std::cout << "-----------------------" << std::endl;
	std::cout << "Testing initial size..." << std::endl;
	if (elements.size() != size)
		std::cout << "\033[33mTEST FAIL\033[0m" << std::endl;
	else
		std::cout << "\033[32mTEST OKAY\033[0m" << std::endl;
	std::cout << "-----------------------" << std::endl;
	std::cout << "Testing the deep copy..." << std::endl;
	Array<std::string> elements2(elements);
	for (unsigned int i = 0; i < elements2.size(); i++)
	{
		if (&elements2[i] == &elements[i])
			std::cout << "\033[33mTEST FAIL\033[0m" << std::endl;
		else
			std::cout << "\033[32mTEST OKAY\033[0m" << std::endl;
		std::cout << "..." << std::endl;
	}
	std::cout << "-----------------------" << std::endl;
	std::cout << "Testing out of bounds handling..." << std::endl;
	try
	{
		std::string word = elements2[size];
	}
	catch(const Array<std::string>::OutOfBoundsException& e)
	{
		std::cerr << "\033[32mTEST OKAY: " << e.what() << "\033[0m\n";
		std::cout << "-----------------------" << std::endl;
	}
	std::cout << "-----------------------" << std::endl;
	std::cout << "Testing out of bounds handling..." << std::endl;
	try
	{
		Array<int> elements3(2);
		elements3[-2] = 0;
	}
	catch(Array<int>::OutOfBoundsException& e)
	{
		std::cerr << "\033[32mTEST OKAY: " << e.what() << "\033[0m\n";
		std::cout << "-----------------------" << std::endl;
		return;
	}
	std::cout << "\033[33mTEST FAIL\033[0m" << std::endl;
}
