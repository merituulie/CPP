/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:13:28 by meskelin          #+#    #+#             */
/*   Updated: 2023/11/06 16:22:27 by meskelin         ###   ########.fr       */
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
void test_valid_presidental();
void test_invalid_presidental();
void test_valid_intern();
void test_invalid_intern();

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

	test_valid_presidental();
	test_invalid_presidental();

	test_valid_intern();
	test_invalid_intern();

	return (0);
}
