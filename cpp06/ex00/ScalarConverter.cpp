/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:45:28 by meskelin          #+#    #+#             */
/*   Updated: 2023/11/20 21:14:51 by meskelin         ###   ########.fr       */
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

ScalarConverter::TYPE ScalarConverter::isChar(const std::string &scalar)
{
	if (scalar.length() == 1
		&& std::isprint(static_cast<unsigned char>(scalar[0]))
		&& !std::isdigit(scalar[0]))
		return ScalarConverter::CHAR;
	return ScalarConverter::NONE;
}

const std::string ScalarConverter::pseudos[] =
{
	"inff",
	"-inff",
	"+inff",
	"nanf",
	"inf",
	"-inf",
	"+inf",
	"nan"
};

ScalarConverter::TYPE ScalarConverter::isPseudo(const std::string &scalar)
{
	int size = ScalarConverter::pseudos->size();
	int i = 0;
	while (i < size)
	{
		if (scalar.compare(ScalarConverter::pseudos[i]))
			return ScalarConverter::TYPE::PSEUDO;
		i++;
	}

	return ScalarConverter::TYPE::NONE;
}

ScalarConverter::TYPE ScalarConverter::isNumber(const std::string &scalar)
{
	bool doubleFound = false;
	bool floatFound = false;
	int offset = 0;
	if (scalar[0] == '+' || scalar[0] == '-')
		offset++;
	for (int i = offset; i < scalar.length() - 1; i++)
	{
		if (!std::isdigit(scalar[i]))
		{
			if (i == 0)
				return ScalarConverter::NONE;
			if ((scalar[i] == '.' && !doubleFound))
			{
				doubleFound = true;
				continue;
			}
			if (scalar[i] == 'f' && !floatFound)
			{
				floatFound = true;
				continue;
			}

			return ScalarConverter::NONE;
		}
	}
	return ScalarConverter::NUMBER;
}

void ScalarConverter::print(const std::string &scalar)
{
}

ScalarConverter::TYPE ScalarConverter::getType(const std::string& scalar)
{
	static ScalarConverter::TYPE (*typeFuncs[3])(const std::string&) =
	{
		isChar,
		isPseudo,
		isNumber
	};

	ScalarConverter::TYPE type = ScalarConverter::NONE;
	for (int i = 0; i < 3; i++)
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
