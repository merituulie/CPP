
#include <iostream>
#include <list>

#include "MutantStack.hpp"

void test_basic()
{
	std::cout << "---- TEST BASIC ----" << std::endl;
	std::cout << "Testing handling the mutant stack..." << std::endl;
	MutantStack<int> mstack;
	if (mstack.size() != 0)
		std::cout << "\033[31mTEST FAIL\033[0m" << std::endl;
	else
		std::cout << "\033[32mTEST OKAY\033[0m" << std::endl;
	mstack.push(1);
	if (mstack.size() != 1 || mstack.top() != 1)
		std::cout << "\033[31mTEST FAIL\033[0m" << std::endl;
	else
		std::cout << "\033[32mTEST OKAY\033[0m" << std::endl;
	mstack.pop();
	if (mstack.size() != 0 || !mstack.empty())
		std::cout << "\033[31mTEST FAIL\033[0m" << std::endl;
	else
		std::cout << "\033[32mTEST OKAY\033[0m" << std::endl;
	std::cout << "--------------------" << std::endl;
	std::cout << "Testing converting to regular stack..." << std::endl;
	try
	{
		std::stack<int> s(mstack);
	}
	catch(const std::exception& e)
	{
		std::cout << "\033[31mTEST FAIL: " << e.what() << "\033[0m\n";
	}
	std::cout << "\033[32mTEST OKAY\033[0m" << std::endl;
	std::cout << "--------------------" << std::endl;
}

void test_iteration()
{
	std::cout << "---- TEST ITERATION ----" << std::endl;
	std::cout << "Testing iterating the mutant stack..." << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(-17);
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	--ite;
	if (*it != 5)
		std::cout << "\033[31mTEST FAIL\033[0m" << std::endl;
	else
		std::cout << "\033[32mTEST OKAY\033[0m" << std::endl;
	if (*ite != 0)
		std::cout << "\033[31mTEST FAIL\033[0m" << std::endl;
	else
		std::cout << "\033[32mTEST OKAY\033[0m" << std::endl;
	it++;
	--ite;
	if (*it == 5)
		std::cout << "\033[31mTEST FAIL\033[0m" << std::endl;
	else
		std::cout << "\033[32mTEST OKAY\033[0m" << std::endl;
	if (*ite == 0)
		std::cout << "\033[31mTEST FAIL\033[0m" << std::endl;
	else
		std::cout << "\033[32mTEST OKAY\033[0m" << std::endl;
	std::cout << "--------------------" << std::endl;
}

void test_const_iteration()
{
	std::cout << "---- TEST CONST ITERATION ----" << std::endl;
	std::cout << "Testing const iterating the mutant stack..." << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(-17);
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::const_iterator it = mstack.begin();
	MutantStack<int>::const_iterator ite = mstack.end();
	--ite;
	if (*it != 5)
		std::cout << "\033[31mTEST FAIL\033[0m" << std::endl;
	else
		std::cout << "\033[32mTEST OKAY\033[0m" << std::endl;
	if (*ite != 0)
		std::cout << "\033[31mTEST FAIL\033[0m" << std::endl;
	else
		std::cout << "\033[32mTEST OKAY\033[0m" << std::endl;
	it++;
	--ite;
	if (*it == 5)
		std::cout << "\033[31mTEST FAIL\033[0m" << std::endl;
	else
		std::cout << "\033[32mTEST OKAY\033[0m" << std::endl;
	if (*ite == 0)
		std::cout << "\033[31mTEST FAIL\033[0m" << std::endl;
	else
		std::cout << "\033[32mTEST OKAY\033[0m" << std::endl;
	std::cout << "--------------------" << std::endl;
}

void test_rev_iteration()
{
	std::cout << "---- TEST REV ITERATION ----" << std::endl;
	std::cout << "Testing rev iterating the mutant stack..." << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(-17);
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	std::list<int> list;
	list.push_back(0);
	list.push_back(737);
	list.push_back(5);
	list.push_back(3);
	list.push_back(-17);
	list.push_back(5);

	MutantStack<int>::reverse_iterator it = mstack.rbegin();
	MutantStack<int>::reverse_iterator ite = mstack.rend();

	std::list<int>::iterator itl = list.begin();
	for (; it != ite && itl != list.end(); it++)
	{
		if (*it != *itl++)
			std::cout << "\033[31mTEST FAIL\033[0m" << std::endl;
	}
	std::cout << "\033[32mTEST OKAY\033[0m" << std::endl;
	std::cout << "--------------------" << std::endl;
}

void test_const_rev_iteration()
{
	std::cout << "---- TEST REV ITERATION ----" << std::endl;
	std::cout << "Testing rev iterating the mutant stack..." << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(-17);
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	std::list<int> list;
	list.push_back(0);
	list.push_back(737);
	list.push_back(5);
	list.push_back(3);
	list.push_back(-17);
	list.push_back(5);

	MutantStack<int>::const_reverse_iterator it = mstack.rbegin();
	MutantStack<int>::const_reverse_iterator ite = mstack.rend();

	std::list<int>::iterator itl = list.begin();
	for (; it != ite && itl != list.end(); it++)
	{
		if (*it != *itl++)
			std::cout << "\033[31mTEST FAIL\033[0m" << std::endl;
	}
	std::cout << "\033[32mTEST OKAY\033[0m" << std::endl;
	std::cout << "--------------------" << std::endl;
}
