/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:26:04 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/25 19:40:32 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUR_H
# define BUR_H

#include <iostream>
#include <stdexcept>
#include "Form.hpp"

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
		bool			signForm(Form& form) const;
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& rhs);

#endif
