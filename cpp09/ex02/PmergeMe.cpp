
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

template <class Container>
void initNumbers(Container *values, int count, char **input)
{
	try
	{
		for (int i = 0; i < count; i++)
		{
			values->push_back(to_int(input[i]));
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		exit(1);
	}

}

template < class Container, class ContainerIt >
void insertionSort(ContainerIt begin, ContainerIt end)
{
	std::iter_swap(begin, std::min_element(begin, end));

	for (ContainerIt current = begin; ++current < end; begin = current)
	{
		for (ContainerIt prev = current; *prev < *begin; --prev, --begin)
			std::iter_swap(begin, prev);
	}
}

template < class Container, class ContainerIt >
Container merge(ContainerIt left, ContainerIt right, ContainerIt end)
{
	ContainerIt itl = left;
	ContainerIt itr = right;
	const ContainerIt left_end = right;
	const ContainerIt right_end = end;

	Container temp;
	while (itl != left_end && itr != right_end)
		temp.push_back(*itl <= *itr ? *itl++ : *itr++);

	temp.insert(temp.end(), itl, left_end);
	temp.insert(temp.end(), itr, right_end);

	return temp;
}

template < class Container, class ContainerIt >
void mergeSort(ContainerIt begin, ContainerIt end)
{
	if (end <= begin + 1)
		return;

	long halfway = std::distance(begin, end) - 1;
	ContainerIt mid = begin + halfway;
	mergeSort<Container, ContainerIt>(begin, mid);
	mergeSort<Container, ContainerIt>(mid, end);
	Container temp = merge<Container, ContainerIt>(begin, mid, end);
	std::move(temp.begin(), temp.end(), begin);
}

template < class Container, class ContainerIt >
void sort(Container *values)
{
	size_t size = values->size();
	if (size < 2)
		return;
	else if (size < 50)
		insertionSort<Container, ContainerIt>(values->begin(), values->end());
	else
		mergeSort<Container, ContainerIt>(values->begin(), values->end());
}

template < class Container, class ContainerIt>
void print(Container values)
{
	for (ContainerIt it = values.begin(); it != values.end(); it++)
	{
		std::cout << *it << " " << std::flush;
	}
	std::cout << std::endl;
}

void PmergeMe::sortAndPrint(int count, char **input)
{
	{
		std::deque<unsigned int> deque;
		initNumbers<std::deque<unsigned int> >(&deque, count, input);
		std::cout << "Before: " << std::flush;
		print<std::deque<unsigned int>, std::deque<unsigned int>::iterator>(deque);
	}

	{
		std::deque<unsigned int> deque;
		std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
		initNumbers<std::deque<unsigned int> >(&deque, count, input);
		sort<std::deque<unsigned int>, std::deque<unsigned int>::iterator>(&deque);
		std::chrono::high_resolution_clock::time_point stop = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double> >(stop - start);
		std::cout << "After: " << std::flush;
		print<std::deque<unsigned int>, std::deque<unsigned int>::iterator>(deque);
		std::cout << "Time to process a range of " << count << " elements with std::deque : " << std::fixed << std::setprecision(6) << time_span.count() << " seconds" << std::endl;
	}

	{
		std::vector<unsigned int> vector;
		std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
		initNumbers<std::vector<unsigned int> >(&vector, count, input);
		sort<std::vector<unsigned int>, std::vector<unsigned int>::iterator>(&vector);
		std::chrono::high_resolution_clock::time_point stop = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double> >(stop - start);
		std::cout << "Time to process a range of " << count << " elements with std::vector : " << std::fixed << std::setprecision(6) << time_span.count() << " seconds" << std::endl;
	}
}
