
#include "RPN.hpp"

RPN::RPN(void)
{
}

RPN::RPN(const RPN& rhs)
{
	*this = rhs;
}

RPN& RPN::operator=(const RPN& rhs)
{
	if (this != &rhs)
		return *this;
	return *this;
}

RPN::~RPN(void)
{
}

static char validOperators[5] =
{
	' ', '+', '-', '/', '*'
};

static bool validInput(std::string input)
{
	if (!isdigit(input[0]) || !isdigit(input[2]))
		return false;

	bool valid = false;
	int charCount = 0;
	int digitCount = 0;
	int i = -1;
	while (input[++i])
	{
		if (isdigit(input[i]))
		{
			digitCount++;
			continue;
		}
		int j = -1;
		while (validOperators[++j])
		{
			if (input[i] == validOperators[j])
			{
				if (j != 0)
					charCount++;

				valid = true;
				break;
			}
		}
		if (!valid)
			return false;
	}

	if (digitCount < 2 || charCount < 1)
		return false;

	return true;
}

void RPN::calculateAndPrint(const std::string input)
{
	if (!validInput(input))
		throw RPN::InvalidInputException();
}

const char *RPN::InvalidInputException::what() const throw()
{
	return "Input is invalid";
}
