/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:53:33 by meskelin          #+#    #+#             */
/*   Updated: 2023/11/06 15:55:32 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"

AForm::AForm(void) : _name("Undefined"), _minGradeToSign(1), _minGradeToExecute(1), _isSigned(false)
{
}

AForm::~AForm(void)
{
}

AForm::AForm(std::string name, unsigned int minGradeToSign, unsigned int minGradeToExecute) : _name(name), _minGradeToSign(minGradeToSign), _minGradeToExecute(minGradeToExecute), _isSigned(false)
{
	if (_minGradeToSign < 1)
		throw AForm::GradeTooHighException();
	else if (_minGradeToSign > 150)
		throw AForm::GradeTooLowException();

	if (_minGradeToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (_minGradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& rhs) : _name(rhs._name), _minGradeToSign(rhs._minGradeToSign), _minGradeToExecute(rhs._minGradeToExecute), _isSigned(false)
{
	*this = rhs;
}

AForm& AForm::operator=(const AForm& rhs)
{
	if (this != &rhs)
	{
		this->_isSigned = rhs._isSigned;
	}

	return *this;
}

const std::string &AForm::getName() const
{
	return this->_name;
}

const int &AForm::getGradeToSign() const
{
	return this->_minGradeToSign;
}
const int &AForm::getGradeToExecute() const
{
	return this->_minGradeToExecute;
}

bool AForm::getIsSigned() const
{
	return this->_isSigned;
}

void AForm::setSigned(bool isSigned)
{
	this->_isSigned = isSigned;
}
bool AForm::beSigned(const Bureaucrat &signer)
{
	std::cout << signer.getName() << " attempts to sign the from " << this->getName() << std::endl;
	int grade = signer.getGrade();
	if (grade > _minGradeToSign)
		throw Bureaucrat::GradeTooLowException();
	if (this->_isSigned)
	{
		std::cout << signer.getName() << " couldn’t sign " << this->getName() << " because the form is already signed.\n";
		return false;
	}

	std::cout << "AForm successfully signed!" << std::endl;
	this->_isSigned = true;
	return true;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	const char *msg = "The grade is too high.";
	return msg;
}

const char* AForm::GradeTooLowException::what() const throw()
{
	const char *msg = "The grade is too low.";
	return msg;
}

const char* AForm::NotSignedException::what() const throw()
{
	const char *msg = "The form is not signed to be executed.";
	return msg;
}

std::ostream& operator<<(std::ostream& out, const AForm &rhs)
{
	out << "AForm: " << rhs.getName() << "\nIs signed: " << rhs.getIsSigned() << "\nMinimum grade needed to sign: " << rhs.getGradeToSign() << "\nMinimum grade needed to execute: " << rhs.getGradeToExecute() << ".\n";
	return out;
}

void AForm::execute(const Bureaucrat &executor) const
{
	std::cout << executor.getName() << " attempts to execute the from " << this->getName() << std::endl;
	int grade = executor.getGrade();
	if (grade > this->_minGradeToExecute)
		throw Bureaucrat::GradeTooLowException();
	if (!this->_isSigned)
		throw AForm::NotSignedException();
}
