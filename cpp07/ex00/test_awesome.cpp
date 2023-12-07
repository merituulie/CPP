
#include "Awesome.hpp"
#include "whatever.hpp"

void test_awesome()
{
	std::cout << "- TEST COMPLEX CLASS -" << std::endl;
	Awesome a(2), b(4);

	swap(a, b);
	if (a.get_n() == 2)
		std::cerr << "\033[33mTEST FAIL\033[0m" << std::endl;
	else
		std::cout << "\033[32mTEST OKAY\033[0m" << std::endl;
	std::cout << "------------------------" << std::endl;
	if (b.get_n() == 4)
		std::cerr << "\033[33mTEST FAIL\033[0m" << std::endl;
	else
		std::cout << "\033[32mTEST OKAY\033[0m" << std::endl;
	std::cout << "------------------------" << std::endl;
	if (max(a, b) == b)
		std::cerr << "\033[33mTEST FAIL\033[0m" << std::endl;
	else
		std::cout << "\033[32mTEST OKAY\033[0m" << std::endl;
	std::cout << "------------------------" << std::endl;
	if (min(a, b) == a)
		std::cerr << "\033[33mTEST FAIL\033[0m" << std::endl;
	else
		std::cout << "\033[32mTEST OKAY\033[0m" << std::endl;
	std::cout << "------------------------" << std::endl;
}
