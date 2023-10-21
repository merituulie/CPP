/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:23:25 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/21 16:23:55 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	this->type = "Dog";
	std::cout << "Dog default constructor called\n";
}

Dog::~Dog(void)
{
	std::cout << "Dog deconstructor called\n";
}

Dog::Dog(const Dog& rhs) : Animal(rhs)
{
	this->type = "Dog";
	std::cout << "Dog copy constructor called\n";
	*this = rhs;
}

Dog &Dog::operator=(const Dog &rhs)
{
	if (this != &rhs)
		this->type = rhs.type;

	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Dog says: HAUUUUU!\n";
}
