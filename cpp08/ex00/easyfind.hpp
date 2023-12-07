
#pragma once

#include <algorithm>
#include <typeinfo>
#include <exception>

#include "InvalidContainerTypeException.hpp"
#include "NotFoundContainerException.hpp"

template<typename T>
typename T::const_iterator easyfind(const T& container, int number)
{
	typename T::const_iterator it = container.begin();
	if (typeid(*it) != typeid(int))
		throw InvalidContainerTypeException();

	typename T::const_iterator element = std::find(it, container.end(), number);
	if (element == container.end())
		throw NotFoundContainerException();
	return element;
}
