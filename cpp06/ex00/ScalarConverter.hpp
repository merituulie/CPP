/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:35:11 by meskelin          #+#    #+#             */
/*   Updated: 2023/11/27 21:11:04 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <iomanip>
#include <limits>

class ScalarConverter
{
	private:
		~ScalarConverter(void);
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter& rhs);

		ScalarConverter& operator=(const ScalarConverter& rhs);

		enum TYPE
		{
			NAN,
			INFPOS,
			INFNEG,
			DOUBLE,
			FLOAT,
			INT,
			CHAR
		};

		static ScalarConverter::TYPE getType(const std::string scalar);
		static void	printConversions(ScalarConverter::TYPE type, char c, int i, float f, double d);

	public:
		static void	convert(const std::string& scalar);
};
