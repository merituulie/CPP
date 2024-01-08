/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:45:28 by meskelin          #+#    #+#             */
/*   Updated: 2023/12/04 12:15:23 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& rhs)
{
	*this = rhs;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter& rhs)
{
	if (this == &rhs)
		return (*this);
	return (*this);
}

ScalarConverter::TYPE ScalarConverter::getType(const std::string scalar)
{
	if (scalar.compare("nan") == 0 || scalar.compare("nanf") == 0)
		return ScalarConverter::NAN;
	if (scalar.compare("+inf") == 0 || scalar.compare("+inff") == 0
		|| scalar.compare("inf") == 0 || scalar.compare("inff") == 0)
		return ScalarConverter::INFPOS;
	if (scalar.compare("-inf") == 0 || scalar.compare("-inff") == 0)
		return ScalarConverter::INFNEG;
	if (scalar.find('.') != std::string::npos)
	{
		if (scalar.find('f') != std::string::npos)
			return ScalarConverter::FLOAT;
		return ScalarConverter::DOUBLE;
	}
	if (scalar.length() == 1 && !isdigit(scalar[0]))
		return ScalarConverter::CHAR;
	for (size_t i = 0; i < scalar.length(); i++)
	{
		if (!isdigit(scalar[0]))
			return ScalarConverter::NONE;
	}
	return ScalarConverter::INT;
}

void	ScalarConverter::printConversions(ScalarConverter::TYPE type, char c, int i, float f, double d)
{
	std::cout << "char: ";
	if (type == NAN || type == INFPOS || type == INFNEG
		|| i < 0 || i > 127)
		std::cout << "impossible\n";
	else if (!isprint(c))
		std::cout << "Non displayable\n";
	else
		std::cout << c << std::endl;

	std::cout << "int: ";
	if (type == NAN || type == INFPOS || type == INFNEG
		|| (type < ScalarConverter::INT
			&& (f > std::numeric_limits<int>::max()
				|| f < std::numeric_limits<int>::min())))
		std::cout << "impossible\n";
	else
		std::cout << i << std::endl;

	std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

static void	convertToNan(float *f, double *d)
{
	*f = std::numeric_limits<float>::quiet_NaN();
	*d = std::numeric_limits<double>::quiet_NaN();
}

static void	convertToInfPos(float *f, double *d)
{
	*f = std::numeric_limits<float>::infinity();
	*d = std::numeric_limits<double>::infinity();
}

static void	convertToInfNeg(float *f, double *d)
{
	*f = -std::numeric_limits<float>::infinity();
	*d = -std::numeric_limits<double>::infinity();
}

static bool	convertToFloat(const char *scalar, char *c, int *i, float *f, double *d)
{
	char* endptr;
	double temp = std::strtod(scalar, &endptr);

	if ((*endptr != '\0' && *endptr != 'f')
		|| temp > std::numeric_limits<float>::max()
		|| temp < -std::numeric_limits<float>::max())
	{
		std::cerr << "Overflowing float input\n";
		return false;
	}

	*f = static_cast<float>(temp);
	*c = static_cast<char>(*f);
	*i = static_cast<int>(*f);
	*d = static_cast<double>(*f);
	return true;
}

static bool	convertToDouble(const char *scalar, char *c, int *i, float *f, double *d)
{
	char *endptr;
	*d = std::strtod(scalar, &endptr);

	if (*endptr != '\0')
	{
		std::cerr << "Overflowing double input\n";
		return false;
	}

	*c = static_cast<char>(*d);
	*i = static_cast<int>(*d);
	*f = static_cast<double>(*d);
	return true;
}

static bool	convertToInt(const std::string scalar, char *c, int *i, float *f, double *d)
{
	char *endptr;
	long long longValue = std::strtol(scalar.c_str(), &endptr, 10);

	if (*endptr != '\0' || longValue > std::numeric_limits<int>::max()
		|| longValue < -std::numeric_limits<int>::max())
	{
		std::cerr << "Overflowing int input\n";
		return false;
	}

	*i = static_cast<int>(longValue);
	*c = static_cast<char>(*i);
	*f = static_cast<float>(*i);
	*d = static_cast<double>(*i);
	return true;
}

static void	convertToChar(const char *input, char *c, int *i, float *f, double *d)
{
	*c = input[0];
	*i = static_cast<int>(*c);
	*f = static_cast<float>(*c);
	*d = static_cast<double>(*c);
}

void ScalarConverter::convert(const std::string& scalar)
{
	char	c = '\0';
	int		i = 0;
	float	f = 0.0f;
	double	d = 0.0;
	const char *input = scalar.c_str();

	ScalarConverter::TYPE type = getType(scalar);
	switch (type)
	{
		case NAN:
			convertToNan(&f, &d);
			break;
		case INFPOS:
			convertToInfPos(&f, &d);
			break;
		case INFNEG:
			convertToInfNeg(&f, &d);
			break;
		case DOUBLE:
			if (convertToDouble(input, &c, &i, &f, &d))
				break;
			else
				return;
		case FLOAT:
			if (convertToFloat(input, &c, &i, &f, &d))
				break;
			else
				return;
		case INT:
			if (convertToInt(input, &c, &i, &f, &d))
				break;
			else
				return;
		case CHAR:
			convertToChar(input, &c, &i, &f, &d);
			break;
		default:
			std::cerr << "Invalid input\n";
			return;
	}

	printConversions(type, c, i, f, d);
}
