
#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc <= 2 || !argv[1] || !argv[2])
	{
		std::cout << "Needs at least two consequent integers to sort\n";
		return 0;
	}

	PmergeMe me;
	me.sortAndPrint(argc - 1, ++argv);
	return 0;
}
