/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:18:20 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/31 17:04:58 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
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
		std::cerr << "\033[32mTEST OKAY\033[0m" << std::endl;
		std::cout << "-------------------------------------------" << std::endl;
		return ;
	}
	std::cerr << "\033[31mFAILED\033[0m" << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
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
		std::cout << "- OVERLOAD -" << std::endl;
		std::cout << "Original: " << bjorn << std::endl;
		bjorn = monica;
		std::cout << "After:    " << bjorn << std::endl;
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << "\033[31mFAIL: " << e.what() << "\033[0m" << std::endl;
		std::cout << "-------------------------------------------" << std::endl;
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << "\033[31mFAIL: " << e.what() << "\033[0m" << std::endl;
		std::cout << "-------------------------------------------" << std::endl;
	}

	std::cerr << "\033[32mTEST OKAY\033[0m" << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
	return ;
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
		std::cerr << "\033[32mTEST OKAY\033[0m" << std::endl;
		std::cout << "-------------------------------------------" << std::endl;
		return ;
	}
	std::cerr << "\033[31mFAILED\033[0m" << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
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
		std::cerr << "\033[31mFAIL: " << e.what() << "\033[0m" << std::endl;
		std::cout << "-------------------------------------------" << std::endl;
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << "\033[31mFAIL: " << e.what() << "\033[0m" << std::endl;
		std::cout << "-------------------------------------------" << std::endl;
	}
	std::cerr << "\033[32mTEST OKAY\033[0m" << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
}

void test_valid_shrubbery()
{
	std::cout << "------------VALID SHRUBBERY----------------" << std::endl;
	try
	{
		ShrubberyCreationForm form("Home");
		std::cout << form << std::endl;
		if (form.getTarget() != "Home"
			|| form.getIsSigned() != false
			|| form.getName() != "ShrubberyCreationForm"
			|| form.getGradeToSign() != 145
			|| form.getGradeToExecute() != 137)
		{
			std::cerr << "\033[31mFAIL\033[0m" << std::endl;
			std::cout << "-------------------------------------------" << std::endl;
		}
		Bureaucrat bur("Bjorn", 130);
		bur.signForm(form);
		bur.executeForm(form);
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << "\033[31mTEST FAILED: " << e.what() << "\033[0m" << std::endl;
		std::cout << "-------------------------------------------" << std::endl;
	}
	catch(const AForm::GradeTooLowException& e)
	{
		std::cerr << "\033[31mFAILED: " << e.what() << "\033[0m" << std::endl;
		std::cout << "-------------------------------------------" << std::endl;
	}
	std::cerr << "\033[32mTEST OKAY\033[0m" << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
}

void test_invalid_shrubbery()
{
	std::cout << "------------INVALID SHRUBBERY--------------" << std::endl;
	try
	{
		std::cout << "- TRYING TO EXECUTE BEFORE SIGNING -" << std::endl;
		ShrubberyCreationForm form("Home");
		Bureaucrat bur("Bjorn", 130);
		bur.executeForm(form);
	}
	catch(const AForm::NotSignedException& e)
	{
		std::cerr << "\033[33mFAIL: " << e.what() << "\033[0m" << std::endl;
		std::cout << "-------------------------------------------" << std::endl;
	}

	try
	{
		std::cout << "- TRYING TO SIGN WITH NO GRADE -" << std::endl;
		ShrubberyCreationForm form("Home");
		std::cout << form << std::endl;
		Bureaucrat bur("Bjorn", 150);
		bur.signForm(form);
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << "\033[33mFAIL: " << e.what() << "\033[0m" << std::endl;
		std::cout << "-------------------------------------------" << std::endl;
		std::cerr << "\033[32mTEST OKAY\033[0m" << std::endl;
		std::cout << "-------------------------------------------" << std::endl;
		return ;
	}
	std::cerr << "\033[31mTEST FAILED\033[0m" << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
}

void test_valid_robotomy()
{
	std::cout << "------------VALID ROBOTOMY----------------" << std::endl;
	try
	{
		RobotomyRequestForm form("Home");
		std::cout << form << std::endl;
		if (form.getTarget() != "Home"
			|| form.getIsSigned() != false
			|| form.getName() != "RobotomyRequestForm"
			|| form.getGradeToSign() != 72
			|| form.getGradeToExecute() != 45)
		{
			std::cerr << "\033[31mFAIL\033[0m" << std::endl;
			std::cout << "-------------------------------------------" << std::endl;
			return ;
		}
		Bureaucrat bur("Bjorn", 30);
		bur.signForm(form);
		std::cout << "- EXECUTE MULTIPLE TIMES -" << std::endl;
		bur.executeForm(form);
		bur.executeForm(form);
		bur.executeForm(form);
		bur.executeForm(form);
		bur.executeForm(form);
		bur.executeForm(form);
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << "\033[31mTEST FAILED: " << e.what() << "\033[0m" << std::endl;
		std::cout << "-------------------------------------------" << std::endl;
	}
	catch(const AForm::GradeTooLowException& e)
	{
		std::cerr << "\033[31mFAILED: " << e.what() << "\033[0m" << std::endl;
		std::cout << "-------------------------------------------" << std::endl;
	}
	std::cerr << "\033[32mTEST OKAY\033[0m" << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
}

void test_invalid_robotomy()
{
	std::cout << "------------INVALID ROBOTOMY--------------" << std::endl;
	try
	{
		std::cout << "- TRYING TO EXECUTE BEFORE SIGNING -" << std::endl;
		RobotomyRequestForm form("Home");
		Bureaucrat bur("Bjorn", 30);
		bur.executeForm(form);
	}
	catch(const AForm::NotSignedException& e)
	{
		std::cerr << "\033[33mFAIL: " << e.what() << "\033[0m" << std::endl;
		std::cout << "-------------------------------------------" << std::endl;
	}

	try
	{
		std::cout << "- TRYING TO SIGN WITH NO GRADE -" << std::endl;
		RobotomyRequestForm form("Home");
		std::cout << form << std::endl;
		Bureaucrat bur("Bjorn", 150);
		bur.signForm(form);
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << "\033[33mFAIL: " << e.what() << "\033[0m" << std::endl;
		std::cout << "-------------------------------------------" << std::endl;
		std::cerr << "\033[32mTEST OKAY\033[0m" << std::endl;
		std::cout << "-------------------------------------------" << std::endl;
		return ;
	}
	std::cerr << "\033[31mTEST FAILED\033[0m" << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
}
