/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:18:20 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/30 13:24:07 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
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

void test_invalid_init_form()
{
	std::cout << "------------TEST INITIALIZATION------------" << std::endl;

	try
	{
		std::cout << "- SIGN GRADE OVER 150 -" << std::endl;
		Form form("Construction permit", 151, 150);
	}
	catch(const Form::GradeTooLowException& e)
	{
		std::cerr << "\033[33mFAIL: " << e.what() << "\033[0m" << std::endl;
		std::cout << "-------------------------------------------" << std::endl;
	}

	try
	{
		std::cout << "- SIGN GRADE LESS THAN 1 -" << std::endl;
		Form form("Construction permit", 0, 70);
	}
	catch(const Form::GradeTooHighException& e)
	{
		std::cerr << "\033[33mFAIL: " << e.what() << "\033[0m" << std::endl;
		std::cout << "-------------------------------------------" << std::endl;
	}

	try
	{
		std::cout << "- EXECUTE GRADE OVER 150 -" << std::endl;
		Form form("Construction permit", 150, 151);
	}
	catch(const Form::GradeTooLowException& e)
	{
		std::cerr << "\033[33mFAIL: " << e.what() << "\033[0m" << std::endl;
		std::cout << "-------------------------------------------" << std::endl;
	}

		try
	{
		std::cout << "- EXECUTE GRADE LESS THAN 1 -" << std::endl;
		Form form("Construction permit", 70, 0);
	}
	catch(const Form::GradeTooHighException& e)
	{
		std::cerr << "\033[33mFAIL: " << e.what() << "\033[0m" << std::endl;
		std::cout << "-------------------------------------------" << std::endl;
	}
}

void test_valid_init_form()
{
	std::cout << "------------VALID--------------------------" << std::endl;
	try
	{
		Form construction("Construction permit", 1, 150);
		std::cout << construction << std::endl;
		Form piping("Piping permit", 70, 150);
		std::cout << piping << std::endl;
		Form nuclearpermit("nuclearpermit", 1, 30);
		std::cout << nuclearpermit << std::endl;
		Form tax(nuclearpermit);
		std::cout << tax << std::endl;
		std::cout << "------------OVERLOAD----------------------" << std::endl;
		std::cout << "Original: " << construction << std::endl;
		construction = piping;
		Bureaucrat bur("Bjorn", 1);
		piping.beSigned(bur);
		construction = piping;
		std::cout << "After: " << construction << std::endl;
	}
	catch(const Form::GradeTooHighException& e)
	{
		std::cerr << "\033[33mFAIL: " << e.what() << "\033[0m" << std::endl;
		std::cout << "-------------------------------------------" << std::endl;
	}
	catch(const Form::GradeTooLowException& e)
	{
		std::cerr << "\033[33mFAIL: " << e.what() << "\033[0m" << std::endl;
		std::cout << "-------------------------------------------" << std::endl;
	}
	std::cout << "\033[32mOKAY\033[0m" << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
}

void test_invalid_signing_form()
{
	std::cout << "------------TEST INVALID SIGNING-------------" << std::endl;
	try
	{
		std::cout << "- SIGN WIHTOUT NEEDED GRADE, BUR -" << std::endl;
		Form form("Construction", 30, 35);
		std::cout << form << std::endl;
		Bureaucrat bur("Bjorn", 70);
		bur.signForm(form);
	}
	catch(const Form::GradeTooLowException& e)
	{
		std::cerr << "\033[33mFAIL: " << e.what() << "\033[0m" << std::endl;
		std::cout << "-------------------------------------------" << std::endl;
	}

	try
	{
		std::cout << "- SIGN WIHTOUT NEEDED GRADE, FORM -" << std::endl;
		Form form("Construction", 30, 35);
		std::cout << form << std::endl;
		Bureaucrat bur("Bjorn", 70);
		form.beSigned(bur);
	}
	catch(const Form::GradeTooLowException& e)
	{
		std::cerr << "\033[33mFAIL: " << e.what() << "\033[0m" << std::endl;
		std::cout << "-------------------------------------------" << std::endl;
	}

	{
		std::cout << "- FORM ALREADY SIGNED -" << std::endl;
		Form form("Construction", 1, 35);
		Bureaucrat bur("Bjorn", 1);
		bur.signForm(form);
		Bureaucrat bur2("Bjorn2", 1);
		if (!bur2.signForm(form))
			std::cout << "\033[33mFAIL\033[0m" << std::endl;
		else
			std::cerr << "\033[31mFAIL\033[0m" << std::endl;
		std::cout << "-------------------------------------------" << std::endl;
	}
}

void test_valid_signing_form()
{
	std::cout << "------------VALID SIGNING------------------" << std::endl;
	try
	{
		Form construction("Construction permit", 1, 150);
		std::cout << construction << std::endl;
		Bureaucrat bur("Bjorn", 1);
		if (!bur.signForm(construction))
		{
			std::cerr << "\031[31mFAIL\031[0m" << std::endl;
			std::cout << "-------------------------------------------" << std::endl;
		}
		std::cout << construction << std::endl;
		std::cout << "\033[32mOKAY\033[0m" << std::endl;
		std::cout << "-------------------------------------------" << std::endl;
		Form piping("Piping permit", 70, 150);
		std::cout << piping << std::endl;
		if (!piping.beSigned(bur))
		{
			std::cerr << "\031[31mFAIL\031[0m" << std::endl;
			std::cout << "-------------------------------------------" << std::endl;
		}
		if (piping.beSigned(bur))
		{
			std::cerr << "\031[31mFAIL\031[0m" << std::endl;
			std::cout << "-------------------------------------------" << std::endl;
		}
		std::cout << piping << std::endl;
		std::cout << "\033[32mOKAY\033[0m" << std::endl;
		std::cout << "-------------------------------------------" << std::endl;
	}
	catch(const Form::GradeTooHighException& e)
	{
		std::cerr << "\033[31mFAIL: " << e.what() << "\033[0m" << std::endl;
		std::cout << "-------------------------------------------" << std::endl;
	}
	catch(const Form::GradeTooLowException& e)
	{
		std::cerr << "\033[31mFAIL: " << e.what() << "\033[0m" << std::endl;
		std::cout << "-------------------------------------------" << std::endl;
	}
}
