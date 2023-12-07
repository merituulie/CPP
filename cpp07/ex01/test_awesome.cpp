
#include "Awesome.hpp"
#include "iter.hpp"

void test_awesome()
{
	std::cout << "- TEST COMPLEX CLASS -" << std::endl;
	Awesome tab[5];
	iter<Awesome>(tab, 5, printNode<Awesome>);
	std::cout << "\033[32mTEST OKAY\033[0m" << std::endl;
	std::cout << "------------------------" << std::endl;
}
