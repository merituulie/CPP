/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:45:28 by meskelin          #+#    #+#             */
/*   Updated: 2023/11/16 21:51:10 by meskelin         ###   ########.fr       */
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
	return (*this);
}

ScalarConverter::TYPE ScalarConverter::isChar(const std::string &scalar)
{
	if (scalar.length() == 1
		&& std::isprint(static_cast<unsigned char>(scalar[0]))
		&& !std::isdigit(scalar[0]))
		return ScalarConverter::CHAR;
	return ScalarConverter::NONE;
}

ScalarConverter::TYPE ScalarConverter::isInt(const std::string &scalar)
{
	int offset = 0;

	if (scalar[offset] == '+' || scalar[offset] == '-')
		offset++;
	for (int i = offset; i < scalar.length(); i++)
	{
		if (!std::isdigit(scalar[i]))
			return ScalarConverter::NONE;
	}
	return ScalarConverter::INT;
}

ScalarConverter::TYPE ScalarConverter::isFloat(const std::string &scalar)
{
	return ScalarConverter::NONE;
}

ScalarConverter::TYPE ScalarConverter::isDouble(const std::string &scalar)
{
	return ScalarConverter::NONE;
}

void ScalarConverter::print(const std::string &scalar)
{
}

ScalarConverter::TYPE ScalarConverter::getType(const std::string& scalar)
{
	static bool (*typeFuncs[4])(const std::string&) =
	{
		isChar,
		isInt,
		isFloat,
		isDouble
	};

	ScalarConverter::TYPE type = ScalarConverter::NONE;
	for (int i = 0; i < 5; i++)
	{
		type = typeFuncs[i](scalar);
		if (type != ScalarConverter::NONE)
			break ;
	}

	return type;
}


void ScalarConverter::convert(const std::string& scalar)
{
	if (scalar.empty())
	{
		print(scalar);
		return ;
	}

	ScalarConverter::TYPE scalarType = getType(scalar);
}
