/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:15:00 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/21 16:25:32 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal()
{
	this->type = "WrongCat";
	std::cout << "WrongCat default constructor called\n";
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat deconstructor called\n";
}

WrongCat::WrongCat(const WrongCat& rhs) : WrongAnimal(rhs)
{
	this->type = "WrongCat";
	std::cout << "WrongCat copy constructor called\n";
	*this = rhs;
}

WrongCat &WrongCat::operator=(const WrongCat &rhs)
{
	if (this != &rhs)
		this->type = rhs.type;

	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "WrongCat says: Miauuuu!\n";
}
