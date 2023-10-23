/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 13:30:01 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/23 12:12:21 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
	std::cout << "----- Basic ClapTrap construction -----\n";
	ClapTrap bella("Bella");
	bella.printTrap();
	bella.takeDamage(1);
	bella.attack("Ufo");
	bella.beRepaired(1);
	std::cout << "---------------------------------------\n\n";

	std::cout << "----- Basic ScavTrap construction -----\n";
	ScavTrap scavBella("ScavBella");
	scavBella.printTrap();
	scavBella.beRepaired(1);
	scavBella.takeDamage(100);
	scavBella.attack("Ufo");
	scavBella.attack("Ufo");
	scavBella.guardGate();
	std::cout << "----------------------------------------\n\n";

	std::cout << "----- Basic FragTrap construction -----\n";
	FragTrap fragBella("FragBella");
	fragBella.printTrap();
	fragBella.beRepaired(1);
	fragBella.takeDamage(100);
	fragBella.attack("Ufo");
	fragBella.attack("Ufo");
	fragBella.highFivesGuys();
	std::cout << "----------------------------------------\n\n";

	std::cout << "----- Basic Diamond trap construction -----\n";
	DiamondTrap diamondBella("diamondBella");
	diamondBella.printTrap();
	diamondBella.whoAmI();
	diamondBella.beRepaired(1);
	diamondBella.takeDamage(100);
	diamondBella.attack("Ufo");
	diamondBella.attack("Ufo");
	diamondBella.highFivesGuys();
	diamondBella.guardGate();
	std::cout << "-------------------------------------------\n\n";

	std::cout << "--------- Operator overloading ---------\n";
	DiamondTrap donna("Donna");
	donna.whoAmI();
	donna.beRepaired(1);
	donna.takeDamage(100);
	donna.attack("Ufo");
	donna.attack("Ufo");
	std::cout << "Calling the = operator overload for Donna.\n";
	donna = diamondBella;
	donna.whoAmI();
	donna.beRepaired(1);
	std::cout << "-----------------------------------------\n\n";

	return 0;
}
