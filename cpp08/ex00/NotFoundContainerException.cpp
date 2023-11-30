
#include "NotFoundContainerException.hpp"

char const *NotFoundContainerException::what() const throw()
{
	return "Element not found from container";
}
