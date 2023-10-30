/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:13:28 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/30 16:14:14 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/Bureaucrat.hpp"
#include <iostream>

void test_invalid_init_bur();
void test_valid_init_bur();
void test_invalid_grade_update_bur();
void test_valid_grade_update_bur();
void test_invalid_init_form();
void test_valid_init_form();
void test_invalid_signing_form();
void test_valid_signing_form();

int main(void)
{
	test_invalid_init_bur();
	test_valid_init_bur();
	test_invalid_grade_update_bur();
	test_valid_grade_update_bur();

	test_invalid_init_form();
	test_valid_init_form();
	test_invalid_signing_form();
	test_valid_signing_form();

	return (0);
}
