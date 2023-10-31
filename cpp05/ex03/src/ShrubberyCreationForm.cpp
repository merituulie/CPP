/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:44:31 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/31 17:16:15 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("Undefined")
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& rhs) : AForm(rhs.getName(), rhs.getGradeToSign(), rhs.getGradeToExecute()), _target(rhs._target)
{
	this->setSigned(rhs.getIsSigned());
	*this = rhs;
}

const std::string& ShrubberyCreationForm::getTarget()
{
	return this->_target;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
	if (this != &rhs)
	{
		this->setSigned(rhs.getIsSigned());
	}

	return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	AForm::execute(executor);

	std::ofstream out;
	out.open(this->_target + "_shrubbery");
	if (out.fail())
	{
		std::cerr << "Error when opening the shrubbery file." << std::endl;
		return ;
	}

	out <<
	"     .{{}}}}}}." << std::endl <<
	"    {{{{{{(`)}}}." << std::endl <<
	"   {{{(`)}}}}}}}}}" << std::endl <<
	"  }}}}}}}}}{{(`){{{" << std::endl <<
	"  }}}}{{{{(`)}}{{{{" << std::endl <<
	" {{{(`)}}}}}}}{}}}}}" << std::endl <<
	"{{{{{{{{(`)}}}}}}}}}}" << std::endl <<
	"{{{{{{{}{{{{(`)}}}}}}" << std::endl <<
	" {{{{{(`){}}{{{{(`)}'" << std::endl <<
	"  {{{{{(`){{{{(`)}'" << std::endl <<
	" ~~~~~~~~~~~~~~~~~~~" << std::endl;
	out.close();
}
