
#include "Span.hpp"

char const* Span::FullException::what() const throw()
{
	return "Span at maximum capacity ";
}

char const* Span::NotEnoughElementsException::what() const throw()
{
	return "Not enough elements in the container to have a span";
}

Span::Span() : _max_size(0)
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
		_max_size = rhs._max_size;
		_ints = rhs._ints;
	}

	return *this;
}

void Span::addNumber(int number)
{
	if (_ints.size() == _max_size)
		throw FullException();
	_ints.push_back(number);
}

void Span::addNumber(std::list<int>::const_iterator begin, std::list<int>::const_iterator end)
{
	if (_ints.size() + std::distance(begin, end) > _max_size)
		throw FullException();
	_ints.insert(_ints.end(), begin, end);
}

unsigned int	Span::shortestSpan()
{
	if (_ints.size() < 2)
		throw NotEnoughElementsException();

	unsigned int shortest = std::numeric_limits<unsigned int>::max();
	for (std::list<int>::const_iterator it1 = _ints.begin(); it1 != _ints.end(); ++it1)
	{
		for (std::list<int>::const_iterator it2 = it1; it2 != _ints.end(); ++it2)
		{
			if (it1 == it2)
				continue;
			unsigned int temp = std::max(*it1, *it2) == *it1 ? (*it1 - *it2) : (*it2 - *it1);
			if (temp < shortest)
				shortest = temp;
		}
	}

	return shortest;
}

unsigned int Span::getMaxSize() const
{
	return _max_size;
}

const std::list<int> Span::getInts() const
{
	return _ints;
}

unsigned int	Span::longestSpan()
{
	if (_ints.size() < 2)
		throw NotEnoughElementsException();

	int min = *std::min_element(_ints.begin(), _ints.end());
	int max = *std::max_element(_ints.begin(), _ints.end());
	unsigned int longestSpan = max - min;

	return longestSpan;
}
