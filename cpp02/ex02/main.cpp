/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 22:30:25 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/10 16:53:26 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Fixed.hpp"

static void	test_bool_operator(bool result, const std::string true_msg,  const std::string false_msg)
{
	if (result)
	{
		std::cout << true_msg << std::endl;
	}
	else
	{
		std::cout << false_msg << std::endl;
	}
}

int main(void) {
	Fixed a;
	Fixed lhs = Fixed(5.05f);
	Fixed rhs = Fixed(2);
	Fixed b(lhs * rhs);

	Fixed c(lhs + rhs);
	std::cout << c << std::endl;
	Fixed d(lhs / rhs);
	std::cout << d << std::endl;
	Fixed e(lhs - rhs);
	std::cout << e << std::endl;
	Fixed f(lhs * rhs);
	std::cout << f << std::endl;

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
	std::cout << Fixed::min(a, b) << std::endl;

	test_bool_operator(a == b, "b is c!", "b is not c!");
	test_bool_operator(a != b, "a is not b!", "a is b!");
	test_bool_operator(a < b, "a is smaller than b!", "a is not smaller than b!");
	test_bool_operator(a > b, "a is bigger than b!", "a is not bigger than b!");

	return 0;
}
