/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:23:25 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/21 17:38:41 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "Dog default constructor called\n";
}

Dog::~Dog(void)
{
	if (this->brain)
		delete this->brain;
	std::cout << "Dog deconstructor called\n";
}

Dog::Dog(const Dog& rhs) : Animal(rhs)
{
	this->type = "Dog";
	this->brain = new Brain(*(rhs.brain));
	std::cout << "Dog copy constructor called\n";
}

Dog &Dog::operator=(const Dog &rhs)
{
	if (this != &rhs)
	{
		Animal::operator=(rhs);
		this->type = rhs.type;
		if (this->brain)
			delete this->brain;
		if (rhs.brain)
			this->brain = new Brain(*(rhs.brain));
	}

	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Dog says: HAUUUUU!\n";
}
