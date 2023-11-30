
#pragma once

#include <exception>
#include <typeinfo>

class InvalidContainerTypeException : public std::exception
{
	public:
		char const* what() const throw();
};
