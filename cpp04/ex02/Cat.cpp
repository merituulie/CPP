/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:15:00 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/21 17:38:26 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "Cat default constructor called\n";
}

Cat::~Cat(void)
{
	if (this->brain)
		delete this->brain;
	std::cout << "Cat deconstructor called\n";
}

Cat::Cat(const Cat& rhs) : Animal(rhs)
{
	this->type = "Cat";
	this->brain = new Brain(*(rhs.brain));
	std::cout << "Cat copy constructor called\n";
}

Cat &Cat::operator=(const Cat &rhs)
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

void Cat::makeSound() const
{
	std::cout << "Cat says: Miauuuu!\n";
}
