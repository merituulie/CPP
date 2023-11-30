
#include "InvalidContainerTypeException.hpp"

char const *InvalidContainerTypeException::what() const throw()
{
	return "Invalid type of a container";
}
