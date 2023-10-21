/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:57:41 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/21 17:48:54 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
# define ANIMAL_H

#include <iostream>

class Animal
{
	protected:
		std::string	type;

	public:
		virtual ~Animal(void);
		Animal(void);
		Animal(const Animal& rhs);

		Animal& operator=(const Animal& rhs);

		virtual void	makeSound() const = 0;
		std::string		getType() const;
};

#endif
