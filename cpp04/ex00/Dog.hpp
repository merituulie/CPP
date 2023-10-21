/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:22:54 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/21 16:23:13 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
# define DOG_H

#include "Animal.hpp"

class Dog : public Animal
{
	public:
		~Dog(void);
		Dog(void);
		Dog(const Dog& rhs);

		Dog& operator=(const Dog& rhs);

		void	makeSound() const;
};

#endif
