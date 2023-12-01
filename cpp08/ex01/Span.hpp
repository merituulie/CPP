
#pragma once

#include <list>
#include <exception>
#include <algorithm>
#include <limits>

#include <iostream>

class Span
{
	private:
		unsigned int	_max_size;
		std::list<int>	_ints;

		Span(void);
	public:
		class FullException : public std::exception
		{
			public:
				char const* what() const throw();
		};

		class NotEnoughElementsException : public std::exception
		{
			public:
				char const* what() const throw();
		};

		class NotEnoughSpace : public std::exception
		{
			public:
				char const* what() const throw();
		};

		~Span(void);
		Span(const Span& rhs);
		Span(unsigned int N);

		Span& operator=(const Span& rhs);

		unsigned int			getMaxSize() const;
		const std::list<int>	getInts() const;

		void addNumber(int number);
		void addNumber(std::list<int>::const_iterator begin, std::list<int>::const_iterator end);

		unsigned int	shortestSpan();
		unsigned int	longestSpan();
};
