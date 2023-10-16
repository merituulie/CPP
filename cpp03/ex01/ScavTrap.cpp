/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 21:04:41 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/16 21:45:01 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	std::cout << "ScavTrap: default constructor is called\n";
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap: constructor with name parameter '" << name << "' is called\n";
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap: deconstructor is called\n";
}

ScavTrap::ScavTrap(const ScavTrap &rhs) : ClapTrap(rhs)
{
	std::cout << "ScavTrap: copy constructor is called\n";
	*this = rhs;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& rhs)
{
	if (this != &rhs)
	{
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}

	return (*this);
}

void ScavTrap::attack(const std::string &target)
{
	if (this->_energyPoints < 1)
	{
		std::cout << "ScavTrap: " << _name << " does not have enough energy to attack!" << std::endl;
		return ;
	}

	this->_energyPoints--;
	std::cout << "ScavTrap: " << _name << " attacks " << target << " causing " << _attackDamage << " points of damage!" << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap: is now in guard mode." << std::endl;
}
