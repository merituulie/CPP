
#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc <= 1 || !argv[1])
	{
		std::cout << "Needs at least one integer as input\n";
		return 0;
	}

	PmergeMe me;
	me.sortAndPrint(argc - 1, ++argv);
	return 0;
}
