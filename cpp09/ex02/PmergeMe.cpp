
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
		throw std::invalid_argument("Invalid int input");
		exit(1);
	}

	if (value > INT_MAX || value < 0)
		throw std::invalid_argument("Invalid int input");

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

std::vector<unsigned int> merge(std::vector<unsigned int>::iterator left, std::vector<unsigned int>::iterator right, std::vector<unsigned int>::iterator end)
{
	std::vector<unsigned int>::iterator itl = left;
	std::vector<unsigned int>::iterator itr = right;
	const std::vector<unsigned int>::iterator left_end = right;
	const std::vector<unsigned int>::iterator right_end = end;

	std::vector<unsigned int> temp;
	while (itl != left_end && itr != right_end)
		temp.push_back(*itl <= *itr ? *itl++ : *itr++);

	temp.insert(temp.end(), itl, left_end);
	temp.insert(temp.end(), itr, right_end);

	return temp;
}

void mergeSort(std::vector<unsigned int>::iterator begin, std::vector<unsigned int>::iterator end)
{
	if (end <= begin + 1)
		return;

	long halfway = std::distance(begin, end) - 1;
	std::vector<unsigned int>::iterator mid = begin + halfway;
	mergeSort(begin, mid);
	mergeSort(mid, end);
	std::vector<unsigned int> temp = merge(begin, mid, end);
	static int i;
	std::cout << i++ << ":" << std::endl;
	std::move(temp.begin(), temp.end(), begin);
	for (std::vector<unsigned int>::iterator it = temp.begin(); it != temp.end(); it++)
	{
		std::cout << *it << ", " << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;
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
