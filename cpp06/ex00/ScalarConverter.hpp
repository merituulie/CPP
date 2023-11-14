/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:35:11 by meskelin          #+#    #+#             */
/*   Updated: 2023/11/14 21:52:18 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class ScalarConverter
{
	private:
		~ScalarConverter(void);
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter& rhs);

		ScalarConverter& operator=(const ScalarConverter& rhs);

		enum TYPE
		{
			NONE,
			CHAR,
			INT,
			FLOAT,
			DOUBLE
		};

		static ScalarConverter::TYPE	getType(const std::string& scalar);

		static ScalarConverter::TYPE	isChar(const std::string& scalar);
		static ScalarConverter::TYPE	isInt(const std::string& scalar);
		static ScalarConverter::TYPE	isFloat(const std::string& scalar);
		static ScalarConverter::TYPE	isDouble(const std::string& scalar);

		static void						print(const std::string& scalar);

	public:
		static void	convert(const std::string& scalar);
};
