/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:45:28 by meskelin          #+#    #+#             */
/*   Updated: 2023/11/27 21:13:29 by meskelin         ###   ########.fr       */
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
		return NAN;
	else if (scalar.compare("+inf") == 0 || scalar.compare("+inff") == 0
			|| scalar.compare("inf") == 0 || scalar.compare("inff"))
		return INFPOS;
	else if (scalar.compare("-inf") == 0 || scalar.compare("-inff") == 0)
		return INFNEG;
	else if (scalar.find('.') != std::string::npos)
	{
		if (scalar.find('f') != std::string::npos)
			return FLOAT;
		return DOUBLE;
	}
	else if (scalar.length() == 1 && !isdigit(scalar[0]))
		return CHAR;
	else
		return INT;
}

void	ScalarConverter::printConversions(ScalarConverter::TYPE type, char c, int i, float f, double d)
{
	std::cout << "char: ";
	if (type == NAN || type == INFPOS || type == INFNEG)
		std::cout << "impossible\n";
	else if (!isprint(c))
		std::cout << "Non displayable\n";
	else
		std::cout << c << std::endl;

	std::cout << "int: ";
	if (type == NAN || type == INFPOS || type == INFNEG)
		std::cout << "impossible\n";
	else
		std::cout << i << std::endl;

	std::cout << "float: " << std::setprecision(1) << f << std::endl;
	std::cout << "double: " << std::setprecision(1) << d << std::endl;
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

static void	convertToFloat(const std::string& scalar, char *c, int *i, float *f, double *d)
{
	try
	{
		*f = std::stof(scalar);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Invalid float input\n";
		return ;
	}

	*c = static_cast<char>(*f);
	*i = static_cast<int>(*f);
	*d = static_cast<double>(*f);
}

static void	convertToDouble(const std::string& scalar, char *c, int *i, float *f, double *d)
{
	try
	{
		*d = std::stod(scalar);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Invalid double input\n";
		return ;
	}

	*c = static_cast<char>(*d);
	*i = static_cast<int>(*d);
	*f = static_cast<double>(*d);
}

static void	convertToChar(const std::string& scalar, char *c, int *i, float *f, double *d)
{
	*c = scalar[0];
	*i = static_cast<int>(*c);
	*f = static_cast<float>(*c);
	*d = static_cast<double>(*c);
}

static void	convertToInt(const std::string& scalar, char *c, int *i, float *f, double *d)
{
	try
	{
		*i = std::stoi(scalar);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Invalid int input\n";
		return ;
	}

	*c = static_cast<char>(*i);
	*f = static_cast<float>(*i);
	*d = static_cast<double>(*i);
}

void ScalarConverter::convert(const std::string& scalar)
{
	char	c = '\0';
	int		i = 0;
	float	f = 0.0f;
	double	d = 0.0;

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
			convertToDouble(scalar, &c, &i, &f, &d);
			break;
		case FLOAT:
			convertToFloat(scalar, &c, &i, &f, &d);
			break;
		case INT:
			convertToInt(scalar, &c, &i, &f, &d);
			break;
		case CHAR:
			convertToChar(scalar, &c, &i, &f, &d);
			break;
		default:
			std::cerr << "Invalid input\n";
			return;
	}

	printConversions(type, c, i, f, d);
}
