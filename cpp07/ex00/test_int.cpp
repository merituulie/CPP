
#include "whatever.hpp"
#include <iostream>

void test_int()
{
		int a = 2;
	int b = 3;

	std::cout << "---- TEST SWAP INT ----" << std::endl;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "Swapping a and b..." << std::endl;
	swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;

	if (a == 2)
		std::cerr << "\033[33mTEST FAIL\033[0m" << std::endl;
	else
		std::cout << "\033[32mTEST OKAY\033[0m" << std::endl;
	std::cout << "------------------------" << std::endl;

	std::cout << "----- TEST MIN INT ----" << std::endl;
	std::cout << "min(a, b) = " << min(a, b) << std::endl;

	if (min(a, b) == a)
		std::cerr << "\033[33mTEST FAIL\033[0m" << std::endl;
	else
		std::cout << "\033[32mTEST OKAY\033[0m" << std::endl;
	std::cout << "-----------------------" << std::endl;

	std::cout << "----- TEST MAX INT ----" << std::endl;
	std::cout << "max(a, b) = " << max(a, b) << std::endl;

	if (max(a, b) == b)
		std::cerr << "\033[33mTEST FAIL\033[0m" << std::endl;
	else
		std::cout << "\033[32mTEST OKAY\033[0m" << std::endl;
	std::cout << "-----------------------" << std::endl;

	std::cout << "--- TEST EQUAL MAX ----" << std::endl;
	a = b;
	if (&max(a, b) == &a)
		std::cerr << "\033[33mTEST FAIL\033[0m" << std::endl;
	else
		std::cout << "\033[32mTEST OKAY\033[0m" << std::endl;
	std::cout << "-----------------------" << std::endl;

	std::cout << "--- TEST EQUAL MIN ----" << std::endl;
	if (&min(a, b) == &a)
		std::cerr << "\033[33mTEST FAIL\033[0m" << std::endl;
	else
		std::cout << "\033[32mTEST OKAY\033[0m" << std::endl;
	std::cout << "-----------------------" << std::endl;
}
