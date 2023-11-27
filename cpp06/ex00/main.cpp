
#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Expecting one argument as a char, an int, a float, a double or a pseudo literal\n";
		return (0);
	}

	std::string scalar(argv[1]);
	ScalarConverter::convert(scalar);

	return (0);
}
