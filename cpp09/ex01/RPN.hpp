
#pragma once

# include <iostream>
# include <cstdlib>
# include <stack>
# include <string.h>

class RPN
{
	private:

		enum OPERATION
		{
			ADD,
			SUB,
			MULTIPLY,
			DIVIDE
		};

		static std::pair<char, RPN::OPERATION> validOperators[4];

		std::stack<int> digits;

		RPN(const RPN& rhs);

		RPN& operator=(const RPN& rhs);

		bool validInput(char *input);
		long calculate(char *input);
		long calculateOperation(int first, int second, OPERATION op);

	public:
		~RPN(void);
		RPN(void);

		void calculateAndPrint(char *input);

		class InvalidInputException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class DivisionByZero : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class OverflowException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};
