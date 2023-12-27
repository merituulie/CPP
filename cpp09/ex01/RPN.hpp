
#pragma once

# include <iostream>
# include <cstdlib>
# include <stack>

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
		bool validInput(std::string input);
		long calculate(const std::string& input);
		void calculateOperation(long *result, int first, OPERATION op);

	public:
		~RPN(void);
		RPN(void);

		void calculateAndPrint(const std::string& input);

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
