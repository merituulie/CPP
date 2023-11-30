
#pragma once

#include <list>
#include <exception>
#include <algorithm>
#include <limits>

class Span
{
	private:
		unsigned int	_max_size = 0;
		std::list<int>	_ints;

		Span(void);
	public:
		class FullException : public std::exception
		{
			public:
				char const* what() const throw();
		};

		class NotFoundException : public std::exception
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

		void addNumber(int number);
		void addNumber(std::list<int>::const_iterator begin, std::list<int>::const_iterator end, int number);

		unsigned int	shortestSpan() const;
		unsigned int	longestSpan() const;
};
