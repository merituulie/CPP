/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:42:15 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/24 15:38:06 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("Nobody"), _grade(150)
{
}

Bureaucrat::~Bureaucrat(void)
{
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& rhs) : _name(rhs._name), _grade(rhs._grade)
{
	*this = rhs;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& rhs)
{
	if (this != &rhs)
		_grade = rhs._grade;

	return *this;
}

const std::string &Bureaucrat::getName() const
{
	return _name;
}

unsigned int Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::setGrade(int grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
}

void Bureaucrat::decrementGrade()
{
	this->setGrade(_grade + 1);
}

void	Bureaucrat::incrementGrade()
{
	this->setGrade(_grade - 1);
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	const char *msg = "Grade too high, maximum grade is 1.";
	return msg;
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	const char *msg = "Grade too low, minimum grade is 150.";
	return msg;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &rhs)
{
	out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return out;
}
