
#include "Span.hpp"

char const* Span::NotEnoughSpace::what() const throw()
{
	return "There is not enough space for the elements to be copied";
}

char const* Span::FullException::what() const throw()
{
	return "Span full";
}

char const* Span::NotFoundException::what() const throw()
{
	return "No span found";
}

Span::Span()
{
}

Span::~Span()
{
}

Span::Span(unsigned int N) : _max_size(N)
{
}

Span::Span(const Span& rhs) : _max_size(rhs._max_size)
{
	*this = rhs;
}

Span& Span::operator=(const Span& rhs)
{
	if (this != &rhs)
	{
		//if (_max_size < rhs._max_size)
		//	throw NotEnoughSpace();

		_max_size = rhs._max_size;
		_ints = rhs._ints;
		//for (std::list<int>::const_iterator it = rhs._ints.begin(); it != rhs._ints.end; it++)
		//{
		//	if (_ints.size() == _max_size)
		//		throw FullException();
		//	_ints.push_back(*it);
		//}
	}

	return *this;
}

void Span::addNumber(int number)
{
	if (_ints.size() == _max_size)
		throw FullException();
	_ints.push_back(number);
}

void Span::addNumber(std::list<int>::const_iterator begin, std::list<int>::const_iterator end, int number)
{
	for (std::list<int>::const_iterator it = begin; it != end; it++)
	{
		if (_ints.size() == _max_size)
			throw FullException();
		_ints.push_back(*it);
	}
}

unsigned int	Span::shortestSpan() const
{
	if (_ints.size() < 2)
		throw NotFoundException();

	std::sort(_ints.begin(), _ints.end());
	unsigned int shortest = std::numeric_limits<unsigned int>::max();
	for (size_t i = 0; i < _ints.size(); i++)
	{
		unsigned int temp = _ints.at(i + 1) - _ints.at(i);
		if (temp < shortest)
			shortest = temp;
	}

	return shortest;
}

unsigned int	Span::longestSpan() const
{
}
