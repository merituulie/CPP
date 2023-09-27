/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:36:14 by meskelin          #+#    #+#             */
/*   Updated: 2023/09/12 10:32:22 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)
{
	this->_weapon = NULL;
}

HumanB::~HumanB()
{
}

void HumanB::setWeapon(Weapon& weapon)
{
	if (weapon.getType().empty())
	{
		std::cout << "Please provide a weapon." << std::endl;
		return;
	}

	this->_weapon = &weapon;
}

void HumanB::attack() const
{
	if (!this->_weapon || this->_weapon->getType().empty())
	{
		std::cout << this->_name << " needs a weapon before they attack." << std::endl;
		return;
	}

	std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}
