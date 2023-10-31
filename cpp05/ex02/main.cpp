/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:13:28 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/31 17:01:24 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/Bureaucrat.hpp"
#include <iostream>

void test_invalid_init_bur();
void test_valid_init_bur();
void test_invalid_grade_update_bur();
void test_valid_grade_update_bur();
void test_invalid_shrubbery();
void test_valid_shrubbery();
void test_valid_robotomy();
void test_invalid_robotomy();

int main(void)
{
	test_invalid_init_bur();
	test_valid_init_bur();
	test_invalid_grade_update_bur();
	test_valid_grade_update_bur();

	test_valid_shrubbery();
	test_invalid_shrubbery();

	test_valid_robotomy();
	test_invalid_robotomy();

	return (0);
}
