
#pragma once

#include <exception>
#include <typeinfo>

class NotFoundContainerException : public std::exception
{
	public:
		char const* what() const throw();
};
