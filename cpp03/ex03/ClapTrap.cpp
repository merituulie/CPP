/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 13:02:50 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/23 12:05:20 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _hitPoints(100), _energyPoints(100), _attackDamage(30)
{
	std::cout << "ClapTrap: Default constructor called\n";
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(100), _energyPoints(100), _attackDamage(30)
{
	std::cout << "ClapTrap: Name constructor called\n";
}

ClapTrap::ClapTrap(const ClapTrap& rhs) :  _name(rhs._name), _hitPoints(rhs._hitPoints), _energyPoints(rhs._energyPoints), _attackDamage(rhs._attackDamage)
{
	std::cout << "ClapTrap: copy constructor called\n";
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap: deconstructor called\n";
}

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}

	return (*this);
}

void ClapTrap::attack(const std::string &target)
{
	if (this->_energyPoints < 1)
	{
		std::cout << "ClapTrap: " << _name << " does not have enough energy to attack!" << std::endl;
		return ;
	}

	this->_energyPoints--;
	std::cout << "ClapTrap: " << _name << " attacks " << target << " causing " << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	int	new_health = this->_hitPoints - amount;
	if (new_health < 0)
		this->_hitPoints = 0;
	else
		this->_hitPoints = new_health;

	std::cout << "ClapTrap: " << _name << " took " << amount << " points of damage and is left with " << _hitPoints << " hit points!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints < 1)
	{
		std::cout << "ClapTrap: " << _name << " does not have enough energy to repair!" << std::endl;
		return ;
	}

	this->_energyPoints--;
	this->_hitPoints += amount;

	std::cout << "ClapTrap: " << _name << " gets repaired for " << amount << " hit points and is left with " << this->_hitPoints << " hit points!" << std::endl;
}

void	ClapTrap::printTrap(void)
{
	std::cout << "Name: " << this->_name << std::endl;
	std::cout << "Hit points: " << this->_hitPoints << std::endl;
	std::cout << "Energy points: " << this->_energyPoints << std::endl;
	std::cout << "Attack damage: " << this->_attackDamage << std::endl;
}
