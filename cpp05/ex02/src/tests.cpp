/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:18:20 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/30 19:57:19 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include <iostream>

void test_invalid_init_bur()
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

void test_valid_init_bur()
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

void test_invalid_grade_update_bur()
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

void test_valid_grade_update_bur()
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

void test_valid_init_shrubbery()
{
	std::cout << "------------VALID SHRUBBERY--------------------" << std::endl;
	try
	{
		ShrubberyCreationForm form("Home");
		std::cout << form << std::endl;
		if (form.getTarget() == "Home"
			&& form.getIsSigned() == false
			&& form.getName() == "ShrubberyCreationForm"
			&& form.getGradeToSign() == 145
			&& form.getGradeToExecute() == 137)
		{
			std::cout << "\033[32mOKAY\033[0m" << std::endl;
			std::cout << "-------------------------------------------" << std::endl;
		}
	}
	catch(const AForm::GradeTooHighException& e)
	{
		std::cerr << "\033[33mFAIL: " << e.what() << "\033[0m" << std::endl;
		std::cout << "-------------------------------------------" << std::endl;
	}
	catch(const AForm::GradeTooLowException& e)
	{
		std::cerr << "\033[33mFAIL: " << e.what() << "\033[0m" << std::endl;
		std::cout << "-------------------------------------------" << std::endl;
	}
		std::cerr << "\031[33mFAIL\031[0m" << std::endl;
		std::cout << "-------------------------------------------" << std::endl;
}
