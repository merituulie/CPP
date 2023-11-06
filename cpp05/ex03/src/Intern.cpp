/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:43:59 by meskelin          #+#    #+#             */
/*   Updated: 2023/11/06 16:50:24 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"

Intern::Intern(void)
{
}

Intern::~Intern(void)
{
}

Intern::Intern(const Intern& rhs)
{
	*this = rhs;
}

Intern& Intern::operator=(const Intern& rhs)
{
	if (this != &rhs)
		return (*this);
	return (*this);
}

static AForm *makeShrubberyForm(const std::string target)
{
	AForm *form;

	try
	{
		form = new ShrubberyCreationForm(target);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Memory allocation issue." << std::endl;
	}

	return form;
}

static AForm *makeRobotomyForm(const std::string target)
{
	AForm *form;

	try
	{
		form = new RobotomyRequestForm(target);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Memory allocation issue." << std::endl;
	}

	return form;
}

static AForm *makePresidentalForm(const std::string target)
{
	AForm *form;

	try
	{
		form = new PresidentialPardonForm(target);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Memory allocation issue." << std::endl;
	}

	return form;
}

static const std::string forms[3] = { "shrubbery creation", "robotomy request", "presidental pardon" };
static AForm* (*makeForm_f[3])(const std::string) =	{ &makeShrubberyForm, &makeRobotomyForm, &makePresidentalForm };

AForm *Intern::makeForm(const std::string form_name, const std::string target)
{
	if (form_name.empty())
		throw AForm::DoesNotExist();

	AForm *ptr = 0;
	for (int i = 0; i < 3; i++)
	{
		if (forms[i].compare(form_name) == 0)
			ptr = (makeForm_f[i])(target);
	}

	if (!ptr)
		throw AForm::DoesNotExist();
	else
		std::cout << "Intern created the form " << form_name << std::endl;
	return (ptr);
}
