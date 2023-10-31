/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:26:04 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/31 12:22:34 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdexcept>

#include "./AForm.hpp"
class AForm;

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;

		Bureaucrat(void);

		void	setGrade(int grade);
	public:
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

		~Bureaucrat(void);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& rhs);

		Bureaucrat& operator=(const Bureaucrat& rhs);

		const std::string&		getName() const;
		unsigned int			getGrade() const;

		void			incrementGrade();
		void			decrementGrade();
		bool			signForm(AForm &form) const;
		void			executeForm(AForm const & form) const;
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& rhs);
