/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:06:35 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/21 16:26:02 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("WrongAnimal")
{
	std::cout << "WrongAnimal default constructor called\n";
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal deconstructor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &rhs) : type(rhs.type)
{
	std::cout << "WrongAnimal copy constructor called\n";
	*this = rhs;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rhs)
{
	if (this != &rhs)
	{
		this->type = rhs.type;
	}

	return *this;
}

void WrongAnimal::makeSound() const
{
	std::cout << this->type << " says: * undefined *\n";
}

std::string WrongAnimal::getType() const
{
	return this->type;
}
