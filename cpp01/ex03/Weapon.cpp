/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:20:12 by meskelin          #+#    #+#             */
/*   Updated: 2023/09/05 17:55:44 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type)
{
}

Weapon::~Weapon()
{
}

void Weapon::setType(std::string type)
{
	if (type.empty())
	{
		std::cout << "Please give a type to the weapon." << std::endl;
		return;
	}

	this->_type = type;
}

const std::string& Weapon::getType()
{
	return this->_type;
}
