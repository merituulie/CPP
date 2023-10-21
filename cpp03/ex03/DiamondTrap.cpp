/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 14:18:39 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/21 15:13:13 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ScavTrap(), FragTrap()
{
	std::cout << "DiamondTrap: Default constructor called!\n";
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap: Deconstructor called!\n";
}

DiamondTrap::DiamondTrap(std::string name) : ScavTrap(name), FragTrap(name)
{
	ClapTrap::_name = name + "_clap_name";
	this->_name = name;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap: Name constructor called!\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap& rhs) : ClapTrap(rhs), ScavTrap(rhs), FragTrap(rhs)
{
	*this = rhs;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_attackDamage = rhs._attackDamage;
		this->_energyPoints = rhs._energyPoints;
	}

	return *this;
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap name: " << DiamondTrap::_name << ", ClapTrap name: " << ClapTrap::_name << std::endl;
}
