
#include <iostream>
#include <vector>
#include <list>

#include "NotFoundContainerException.hpp"
#include "InvalidContainerTypeException.hpp"
#include "easyfind.hpp"

void test_list()
{
	std::cout << "---- TEST LIST ----" << std::endl;
	std::cout << "Initializing int list { 1, 2, 3, 4, 5 }..." << std::endl;
	int myInts[5] = { 1, -2, 3, 4, 5 };
	std::list<int> ints(myInts, myInts + sizeof(myInts) / sizeof(int));

	std::cout << "Finding 1 from the list..." << std::endl;
	std::list<int>::const_iterator it = ::easyfind(ints, 1);
	if (*it != 1)
		std::cout << "\033[31mTEST FAIL\033[0m" << std::endl;
	else
		std::cout << "\033[32mTEST OKAY\033[0m" << std::endl;
	std::cout << "--------------------" << std::endl;
	std::cout << "Finding 6 from the list..." << std::endl;
	try
	{
		it = ::easyfind(ints, 6);
	}
	catch (const NotFoundContainerException& e)
	{
		std::cout << "\033[32mTEST OKAY: \033[33m" << e.what() << "\033[0m" << std::endl;
	}
	std::cout << "--------------------" << std::endl;
	std::cout << "Using template with wrong type..." << std::endl;
	float myFloats[5] = { 1.0f, -2.3f, 3.1f, 4.65f, 5.89f };
	std::list<float> floats(myFloats, myFloats + sizeof(myFloats) / sizeof(float));
	try
	{
		std::list<float>::const_iterator it = ::easyfind(floats, 1.0f);
		if (*it == 1.0f)
			std::cout << "\033[31mTEST FAIL\033[0m" << std::endl;
	}
	catch (const InvalidContainerTypeException& e)
	{
		std::cout << "\033[32mTEST OKAY: \033[33m" << e.what() << "\033[0m" << std::endl;
	}
	std::cout << "--------------------" << std::endl;
}

void test_vector()
{
	std::cout << "---- TEST VECTOR ----" << std::endl;
	std::cout << "Initializing int vector { 0, 1, 2, 3, 4 }..." << std::endl;
	std::vector<int> ints;
	for (int i = 0; i < 5; i++)
		ints.push_back(i);
	std::cout << "Finding 1 from the vector..." << std::endl;
	std::vector<int>::const_iterator it_vector = easyfind(ints, 1);
	if (*it_vector != 1)
		std::cout << "\033[31mTEST FAIL\033[0m" << std::endl;
	else
		std::cout << "\033[32mTEST OKAY\033[0m" << std::endl;
	std::cout << "--------------------" << std::endl;
	std::cout << "Finding 6 from the vector..." << std::endl;
	try
	{
		it_vector = ::easyfind(ints, 6);
	}
	catch (const NotFoundContainerException& e)
	{
		std::cout << "\033[32mTEST OKAY: \033[33m" << e.what() << "\033[0m" << std::endl;
	}
	std::cout << "--------------------" << std::endl;
	std::cout << "Using template with wrong type..." << std::endl;
	float myFloats[5] = { 1.0f, -2.3f, 3.1f, 4.65f, 5.89f };
	std::vector<float> floats(myFloats, myFloats + sizeof(myFloats) / sizeof(float));
	try
	{
		std::vector<float>::const_iterator it = ::easyfind(floats, 1.0f);
		if (*it == 1.0f)
			std::cout << "\033[31mTEST FAIL\033[0m" << std::endl;
	}
	catch (const InvalidContainerTypeException& e)
	{
		std::cout << "\033[32mTEST OKAY: \033[33m" << e.what() << "\033[0m" << std::endl;
	}
	std::cout << "--------------------" << std::endl;
}
