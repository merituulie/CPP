
#include "whatever.hpp"
#include <iostream>

void test_string()
{
	std::string a = "chaine1";
	std::string b = "chaine2";

	std::cout << "---- TEST SWAP STRING ----" << std::endl;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "Swapping a and b..." << std::endl;
	swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;

	if (a == "chaine1")
		std::cerr << "\033[33mTEST FAIL\033[0m" << std::endl;
	else
		std::cout << "\033[32mTEST OKAY\033[0m" << std::endl;
	std::cout << "------------------------" << std::endl;

	std::cout << "----- TEST MIN STRING ----" << std::endl;
	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;

	if (::min(a, b) == a)
		std::cerr << "\033[33mTEST FAIL\033[0m" << std::endl;
	else
		std::cout << "\033[32mTEST OKAY\033[0m" << std::endl;
	std::cout << "-----------------------" << std::endl;

	std::cout << "----- TEST MAX STRING ----" << std::endl;
	std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

	if (::max(a, b) == b)
		std::cerr << "\033[33mTEST FAIL\033[0m" << std::endl;
	else
		std::cout << "\033[32mTEST OKAY\033[0m" << std::endl;
	std::cout << "-----------------------" << std::endl;

	std::cout << "--- TEST EQUAL MAX ----" << std::endl;
	a = b;
	if (&::max(a, b) == &a)
		std::cerr << "\033[33mTEST FAIL\033[0m" << std::endl;
	else
		std::cout << "\033[32mTEST OKAY\033[0m" << std::endl;
	std::cout << "-----------------------" << std::endl;

	std::cout << "--- TEST EQUAL MIN ----" << std::endl;
	if (&::min(a, b) == &a)
		std::cerr << "\033[33mTEST FAIL\033[0m" << std::endl;
	else
		std::cout << "\033[32mTEST OKAY\033[0m" << std::endl;
	std::cout << "-----------------------" << std::endl;
}
