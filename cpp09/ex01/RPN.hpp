
#pragma once

# include <iostream>
# include <iomanip>
# include <limits>
# include <cstdlib>
# include <cfloat>
# include <string>
# include <algorithm>

class RPN
{
	private:
		static char *validOperators;

		RPN(const RPN& rhs);

		RPN& operator=(const RPN& rhs);
	public:
		~RPN(void);
		RPN(void);

		void calculateAndPrint(const std::string input);

		class InvalidInputException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};
