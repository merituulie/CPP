
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

bool RPN::validInput(char *input)
{
	bool valid = false;
	int charCount = 0;
	int digitCount = 0;
	int i = -1;

	while (input[++i])
	{
		valid = false;
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
				if (input[i] == '-' && input[i + 1] && isdigit(input[i + 1]))
				{
					digitCount++;
					i++;
					valid = true;
					break;
				}

				charCount++;
				valid = true;
				break;
			}
		}
		if (!valid)
			return false;
	}

	if (digitCount < 2 || charCount < 1 || charCount != (digitCount - 1))
		return false;

	return true;
}

long RPN::calculateOperation(int first, int second, OPERATION op)
{
	long result = 0;

	switch (op)
	{
		case ADD:
			result = first + second;
			break;
		case SUB:
			result = first - second;
			break;
		case MULTIPLY:
			result = first * second;
			break;
		case DIVIDE:
		{
			if (second == 0)
				throw DivisionByZero();
			else
				result = first / second;
			break;
		}
		default:
			throw InvalidInputException();
			break;
	}

	if (result < INT_MIN || result > INT_MAX)
		throw OverflowException();

	return result;
}

long RPN::calculate(char *input)
{
	long result = 0;

	std::string s_input = std::string(input);
	for (size_t i = 0; i < s_input.length(); i++)
	{
		if (isspace(input[i]))
			continue;
		else if (isdigit(input[i]))
		{
			int value = atoi(s_input.substr(i, 1).c_str());
			digits.push(value);
			continue;
		}
		else
		{
			int j = -1;
			while (validOperators[++j].first)
			{
				if (input[i] != validOperators[j].first)
					continue;

				if (input[i] == '-' && input[i + 1] && isdigit(input[i + 1]))
				{
					int value = atoi(s_input.substr(i, 2).c_str());
					digits.push(value);
					i++;
					break;
				}

				if (digits.empty())
					throw InvalidInputException();
				int second = digits.top();
				digits.pop();

				if (digits.empty())
					throw InvalidInputException();
				int first = digits.top();
				digits.pop();

				result = calculateOperation(first, second, validOperators[j].second);
				digits.push(result);

				break;
			}
		}
	}

	return result;
}

void RPN::calculateAndPrint(char *input)
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

const char *RPN::OverflowException::what() const throw()
{
	return "The result overflows an integer value";
}
