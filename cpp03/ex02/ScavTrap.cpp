/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 13:13:06 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/21 13:42:26 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	std::cout << "ScavTrap: Default constructor called\n";
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap: Default constructor called\n";
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap: Name constructor called\n";
}

ScavTrap::ScavTrap(const ScavTrap& rhs) : ClapTrap(rhs), _isGuarding(rhs._isGuarding)
{
	std::cout << "ScavTrap: Copy constructor called\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap& rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
		this->_isGuarding = rhs._isGuarding;
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
	this->_isGuarding = true;
}
