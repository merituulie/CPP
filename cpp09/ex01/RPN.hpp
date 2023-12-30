
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

		void cleanUp();
		bool validInput(char *input);
		long calculate(char *input);
		void calculateOperation(long *result, int first, OPERATION op);
		bool validOperation(char *input, int i);

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
};
