
#pragma once

#include <iostream>
#include <string>
#include <algorithm>
#include <limits.h>
#include <vector>
#include <set>

class PmergeMe
{
	public:
		PmergeMe();
		~PmergeMe();

		void sortAndPrint(int count, char **input);

	private:
		PmergeMe(const PmergeMe& rhs);

		PmergeMe& operator=(const PmergeMe& rhs);
};
