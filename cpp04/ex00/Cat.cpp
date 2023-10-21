/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:15:00 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/21 16:22:26 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
	this->type = "Cat";
	std::cout << "Cat default constructor called\n";
}

Cat::~Cat(void)
{
	std::cout << "Cat deconstructor called\n";
}

Cat::Cat(const Cat& rhs) : Animal(rhs)
{
	this->type = "Cat";
	std::cout << "Cat copy constructor called\n";
	*this = rhs;
}

Cat &Cat::operator=(const Cat &rhs)
{
	if (this != &rhs)
		this->type = rhs.type;

	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Cat says: Miauuuu!\n";
}
