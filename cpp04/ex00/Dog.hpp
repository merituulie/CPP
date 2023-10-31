/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:22:54 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/23 15:15:18 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
# define DOG_H

#include "Animal.hpp"

class Dog : public Animal
{
	public:
		virtual ~Dog(void);
		Dog(void);
		Dog(const Dog& rhs);

		Dog& operator=(const Dog& rhs);

		void	makeSound() const;
};

#endif
