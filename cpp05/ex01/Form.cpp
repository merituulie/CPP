/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:53:33 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/30 13:19:36 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : _name("Undefined"), _minGradeToSign(1), _minGradeToExecute(1), _isSigned(false)
{
}

Form::~Form(void)
{
}

Form::Form(std::string name, unsigned int minGradeToSign, unsigned int minGradeToExecute) : _name(name), _minGradeToSign(minGradeToSign), _minGradeToExecute(minGradeToExecute), _isSigned(false)
{
	if (_minGradeToSign < 1)
		throw Form::GradeTooHighException();
	else if (_minGradeToSign > 150)
		throw Form::GradeTooLowException();

	if (_minGradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (_minGradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& rhs) : _name(rhs._name), _minGradeToSign(rhs._minGradeToSign), _minGradeToExecute(rhs._minGradeToExecute), _isSigned(rhs._isSigned)
{
	*this = rhs;
}

Form& Form::operator=(const Form& rhs)
{
	if (this != &rhs)
	{
		this->_isSigned = rhs._isSigned;
	}

	return *this;
}

const std::string &Form::getName() const
{
	return this->_name;
}

const int &Form::getGradeTosSign() const
{
	return this->_minGradeToSign;
}
const int &Form::getGradeToExecute() const
{
	return this->_minGradeToExecute;
}

bool Form::getIsSigned() const
{
	return this->_isSigned;
}

bool Form::beSigned(const Bureaucrat &signer)
{
	std::cout << signer.getName() << " attempts to sign the from " << this->getName() << std::endl;
	int grade = signer.getGrade();
	if (grade > _minGradeToSign)
		throw Form::GradeTooLowException();
	if (this->_isSigned)
	{
		std::cout << signer.getName() << " couldn’t sign " << this->getName() << " because the form is already signed.\n";
		return false;
	}

	std::cout << "Form successfully signed!" << std::endl;
	this->_isSigned = true;
	return true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	const char *msg = "The grade is too high, maximum grade is 1.";
	return msg;
}

const char* Form::GradeTooLowException::what() const throw()
{
	const char *msg = "The grade is too low, minimum grade is 150.";
	return msg;
}

std::ostream& operator<<(std::ostream& out, const Form &rhs)
{
	out << "Form: " << rhs.getName() << "\nIs signed: " << rhs.getIsSigned() << "\nMinimum grade needed to sign: " << rhs.getGradeTosSign() << "\nMinimum grade needed to execute: " << rhs.getGradeToExecute() << ".\n";
	return out;
}
