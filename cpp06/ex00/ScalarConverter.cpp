/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:45:28 by meskelin          #+#    #+#             */
/*   Updated: 2023/11/14 21:51:43 by meskelin         ###   ########.fr       */
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

	return ScalarConverter::NONE;
}

ScalarConverter::TYPE ScalarConverter::isInt(const std::string &scalar)
{
	return ScalarConverter::NONE;
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
	static ScalarConverter::TYPE (*typeFuncs[4])(const std::string&) =
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
