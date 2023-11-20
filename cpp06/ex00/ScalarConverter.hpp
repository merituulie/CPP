/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:35:11 by meskelin          #+#    #+#             */
/*   Updated: 2023/11/20 21:06:39 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdlib.h>
#include <climits>

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
			PSEUDO,
			NUMBER,
		};


		static ScalarConverter::TYPE	getType(const std::string& scalar);

		static ScalarConverter::TYPE	isChar(const std::string& scalar);
		static ScalarConverter::TYPE	isPseudo(const std::string& scalar);
		static ScalarConverter::TYPE	isNumber(const std::string &scalar);

		static void						print(const std::string& scalar);

	public:
		static const std::string pseudos[];

		static void	convert(const std::string& scalar);
};
