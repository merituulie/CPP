/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:06:35 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/21 17:30:24 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : type("Animal")
{
	std::cout << "Animal default constructor called\n";
}

Animal::~Animal(void)
{
	std::cout << "Animal deconstructor called\n";
}

Animal::Animal(const Animal &rhs) : type(rhs.type)
{
	std::cout << "Animal copy constructor called\n";
	*this = rhs;
}

Animal &Animal::operator=(const Animal &rhs)
{
	if (this != &rhs)
		this->type = rhs.type;

	return *this;
}

void Animal::makeSound() const
{
	std::cout << this->type << " says: * undefined *\n";
}

std::string Animal::getType() const
{
	return this->type;
}
