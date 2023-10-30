/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:41:13 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/30 12:36:24 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		const int			_minGradeToSign;
		const int			_minGradeToExecute;
		bool				_isSigned;

		Form(void);
	public:
		~Form(void);
		Form(std::string name, unsigned int minGradeToSign, unsigned int minGradeToExecute);
		Form(const Form& rhs);

		Form& operator=(const Form& rhs);

		const std::string	&getName() const;
		const int			&getGradeTosSign() const;
		const int			&getGradeToExecute() const;
		bool				getIsSigned() const;

		bool				beSigned(const Bureaucrat &signer);

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& out, const Form& rhs);
