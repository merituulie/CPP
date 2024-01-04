
#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
}

PmergeMe& PmergeMe::operator=(const PmergeMe& rhs)
{
	if (this != &rhs)
		return *this;
	return *this;
}

static unsigned int to_int(char *str)
{
	int value = 0;
	try
	{
		value = std::stoi(str);
	}
	catch (const std::exception& e)
	{
		throw std::invalid_argument("Overflowing int input");
		exit(1);
	}

	if (value > INT_MAX || value < 0)
		throw std::invalid_argument("Overflowing int input");

	return static_cast<unsigned int>(value);
}

void PmergeMe::initNumbers(std::vector<unsigned int> *vector, int count, char **input)
{
	try
	{
		for (int i = 0; i < count; i++)
		{
			vector->push_back(to_int(input[i]));
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		exit(1);
	}

}

void insertionSort(std::vector<unsigned int>::iterator begin, std::vector<unsigned int>::iterator end)
{
	std::iter_swap(begin, std::min_element(begin, end));

	for (std::vector<unsigned int>::iterator current = begin; ++current < end; begin = current)
	{
		for (std::vector<unsigned int>::iterator prev = current; *prev < *begin; --prev, --begin)
			std::iter_swap(begin, prev);
	}
}

void merge(std::vector<unsigned int>::iterator begin, std::vector<unsigned int>::iterator mid, std::vector<unsigned int>::iterator end)
{
	std::iter_swap(begin, std::min_element(begin, end));
	std::iter_swap(mid, std::min_element(mid, end));
	std::cout << "merge: " << *begin << " and " << *mid << " and "<< *end << std::endl;
}

void mergeSort(std::vector<unsigned int>::iterator begin, std::vector<unsigned int>::iterator end)
{
	if (end <= begin + 1)
		return;

	long halfway = std::distance(begin, end) - 1;
	std::vector<unsigned int>::iterator mid = begin + halfway;
	mergeSort(begin, mid);
	mergeSort(mid, end);
	merge(begin, mid, end);
}

void sort(std::vector<unsigned int> *values)
{
	//if (values->size() < 50)
	//{
	//	insertionSort(values->begin(), values->end());
	//}
	//else
	//{
		mergeSort(values->begin(), values->end());
	//}
}

void PmergeMe::sortAndPrint(int count, char **input)
{
	std::vector<unsigned int> vector;

	initNumbers(&vector, count, input);
	for (std::vector<unsigned int>::iterator it = vector.begin(); it != vector.end(); it++)
	{
		std::cout << *it << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;

	sort(&vector);
	for (std::vector<unsigned int>::iterator it = vector.begin(); it != vector.end(); it++)
	{
		std::cout << *it << std::endl;
	}
}
