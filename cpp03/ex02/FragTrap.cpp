/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 13:26:02 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/21 13:41:31 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	std::cout << "FragTrap: Default constructor called\n";
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap: Name constructor called\n";
}

FragTrap::FragTrap(const FragTrap& rhs) : ClapTrap(rhs)
{
	std::cout << "FragTrap: Copy constructor called\n";
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap: Deconstructors called\n";
}

FragTrap& FragTrap::operator=(const FragTrap& rhs)
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

void FragTrap::attack(const std::string &target)
{
	if (this->_energyPoints < 1)
	{
		std::cout << "FragTrap: " << _name << " does not have enough energy to attack!" << std::endl;
		return ;
	}

	this->_energyPoints--;
	std::cout << "FragTrap: " << _name << " attacks " << target << " causing " << _attackDamage << " points of damage!" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap: is high fiving people." << std::endl;
}
