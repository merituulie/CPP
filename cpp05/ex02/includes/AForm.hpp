/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:41:13 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/30 18:36:31 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		const int			_minGradeToSign;
		const int			_minGradeToExecute;
		bool				_isSigned;

		AForm(void);
	protected:
		void AForm::setSigned(bool isSigned);
	public:
		virtual ~AForm(void);
		AForm(std::string name, unsigned int minGradeToSign, unsigned int minGradeToExecute);
		AForm(const AForm& rhs);

		AForm& operator=(const AForm& rhs);

		const std::string	&getName() const;
		const int			&getGradeToSign() const;
		const int			&getGradeToExecute() const;
		bool				getIsSigned() const;

		bool				beSigned(const Bureaucrat &signer);
		virtual void		execute(const Bureaucrat &executor) const = 0;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class NotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& out, const AForm& rhs);
