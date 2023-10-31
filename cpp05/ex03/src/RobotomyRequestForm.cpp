/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:44:31 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/31 17:10:54 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("Undefined")
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& rhs) : AForm(rhs.getName(), rhs.getGradeToSign(), rhs.getGradeToExecute()), _target(rhs._target)
{
	this->setSigned(rhs.getIsSigned());
	*this = rhs;
}

const std::string& RobotomyRequestForm::getTarget()
{
	return this->_target;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
	if (this != &rhs)
	{
		this->setSigned(rhs.getIsSigned());
	}

	return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	AForm::execute(executor);

	std::cout << "DrrrrrRRRrrRRRRRRrrRRRrrrrrrr...." << std::endl;
	float random = float(rand()) / float(RAND_MAX);
	if (random >= 0.5)
		std::cout << "\033[32m" << this->_target << " has been robotomized!" << "\033[0m" << std::endl;
	else
		std::cout << "\033[31m" << this->_target << " robotomy has failed." << "\033[0m" << std::endl;
}
