/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:13:28 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/25 19:42:17 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

static void test_invalid_init_bur()
{
	std::cout << "------------TEST INITIALIZATION------------" << std::endl;

	try
	{
		std::cout << "- GRADE OVER 150 -" << std::endl;
		Bureaucrat bjorn("Bjorn", 151);
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << "\033[33mFAIL: " << e.what() << "\033[0m" << std::endl;
		std::cout << "-------------------------------------------" << std::endl;
	}

	try
	{
		std::cout << "- GRADE LESS THAN 1 -" << std::endl;
		Bureaucrat bjorn("Bjorn", 0);
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << "\033[33mFAIL: " << e.what() << "\033[0m" << std::endl;
		std::cout << "-------------------------------------------" << std::endl;
	}

	try
	{
		std::cout << "- GRADE LESS THAN 1 -" << std::endl;
		Bureaucrat bjorn("Bjorn", -100);
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << "\033[33mFAIL: " << e.what() << "\033[0m" << std::endl;
		std::cout << "-------------------------------------------" << std::endl;
	}
}

static void test_valid_init_bur()
{
	std::cout << "------------VALID--------------------------" << std::endl;
	try
	{
		Bureaucrat bjorn("Bjorn", 1);
		std::cout << bjorn << std::endl;
		Bureaucrat lisa("Lisa", 150);
		std::cout << lisa << std::endl;
		Bureaucrat monica("Monica", 75);
		std::cout << monica << std::endl;
		Bureaucrat monicasFan(monica);
		std::cout << monicasFan << std::endl;
		std::cout << "------------OVERLOAD----------------------" << std::endl;
		std::cout << "Original: " << bjorn << std::endl;
		bjorn = monica;
		std::cout << "After:    " << bjorn << std::endl;
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << "\033[33mFAIL: " << e.what() << "\033[0m" << std::endl;
		std::cout << "-------------------------------------------" << std::endl;
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << "\033[33mFAIL: " << e.what() << "\033[0m" << std::endl;
		std::cout << "-------------------------------------------" << std::endl;
	}
	std::cout << "\033[32mOKAY\033[0m" << std::endl;
}

static void test_invalid_grade_update_bur()
{
	std::cout << "------------TEST GRADE UPDATE-------------" << std::endl;

	try
	{
		std::cout << "- INCREASE OVER 150 -" << std::endl;
		Bureaucrat bjorn("Bjorn", 150);
		bjorn.decrementGrade();
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << "\033[33mFAIL: " << e.what() << "\033[0m" << std::endl;
		std::cout << "-------------------------------------------" << std::endl;
	}

	try
	{
		std::cout << "- INVALID LESS THAN 1 -" << std::endl;
		Bureaucrat bjorn("Bjorn", 1);
		bjorn.incrementGrade();
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << "\033[33mFAIL: " << e.what() << "\033[0m" << std::endl;
		std::cout << "-------------------------------------------" << std::endl;
	}
}

static void test_valid_grade_update_bur()
{
	std::cout << "------------VALID--------------------------" << std::endl;
	try
	{
		Bureaucrat bjorn("Bjorn", 1);
		std::cout << bjorn << std::endl;
		bjorn.decrementGrade();
		std::cout << bjorn << std::endl;
		bjorn.incrementGrade();
		std::cout << bjorn << std::endl;
		Bureaucrat lisa("Lisa", 70);
		std::cout << lisa << std::endl;
		lisa.incrementGrade();
		std::cout << lisa << std::endl;
		lisa.decrementGrade();
		std::cout << lisa << std::endl;
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << "\033[33mFAIL: " << e.what() << "\033[0m" << std::endl;
		std::cout << "-------------------------------------------" << std::endl;
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << "\033[33mFAIL: " << e.what() << "\033[0m" << std::endl;
		std::cout << "-------------------------------------------" << std::endl;
	}
	std::cout << "\033[32mOKAY\033[0m" << std::endl;
}

int main(void)
{
	test_invalid_init_bur();
	test_valid_init_bur();
	test_invalid_grade_update_bur();
	test_valid_grade_update_bur();

	// TODO addd tests to form handling

	return (0);
}
