
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
	digits.empty();
}

std::pair<char, RPN::OPERATION> RPN::validOperators[4] =
{
	std::make_pair('+', ADD),
	std::make_pair('-', SUB),
	std::make_pair('/', DIVIDE),
	std::make_pair('*', MULTIPLY)
};

bool RPN::validInput(std::string input)
{
	if (!isdigit(input[0]) || !isdigit(input[2]))
		return false;

	bool valid = false;
	int charCount = 0;
	int digitCount = 0;
	int i = -1;
	while (input[++i])
	{
		if (isspace(input[i]))
			continue;
		if (isdigit(input[i]))
		{
			digitCount++;
			continue;
		}
		int j = -1;
		while (validOperators[++j].first)
		{
			if (input[i] == validOperators[j].first)
			{
				charCount++;
				valid = true;
				break;
			}
		}
		if (!valid)
			return false;
	}


	if (digitCount < 2 || charCount < 1 || charCount >= digitCount || charCount != (digitCount - 1))
		return false;

	return true;
}

void RPN::calculateOperation(long *result, int first, OPERATION op)
{
	switch (op)
	{
		case ADD:
			*result += first;
			break;
		case SUB:
			*result -= first;
			break;
		case MULTIPLY:
			*result *= first;
			break;
		case DIVIDE:
		{
			if (*result == 0)
				throw DivisionByZero();
			else
				*result /= first;
			break;
		}
		default:
			// THROW EXCEPTION
			break;
	}
}

long RPN::calculate(const std::string& input)
{
	long result = 0;
	bool firstTime = true;

	for (size_t i = 0; i < input.length(); i++)
	{
		if (isspace(input[i]))
			continue;
		else if (isdigit(input[i]))
		{
			int value = atoi(input.substr(i, 1).c_str());
			digits.push(value);
			continue;
		}
		else
		{
			int j = -1;
			while (validOperators[++j].first)
			{
				if (input[i] == validOperators[j].first)
				{
					if (firstTime)
					{
						firstTime = false;
						result = digits.top();
						digits.pop();
					}
					int first = digits.top();
					digits.pop();
					calculateOperation(&result, first, validOperators[j].second);
					break;
				}
			}
		}
	}

	return result;
}

void RPN::calculateAndPrint(const std::string& input)
{
	if (!validInput(input))
		throw RPN::InvalidInputException();

	long result = calculate(input);
	std::cout << result << std::endl;

	digits.empty();
}

const char *RPN::InvalidInputException::what() const throw()
{
	return "Input is invalid";
}

const char *RPN::DivisionByZero::what() const throw()
{
	return "Division by zero value";
}
