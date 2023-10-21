/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 21:13:16 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/21 12:28:32 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
	std::cout << "----- Basic ClapTrap construction -----\n";
	ClapTrap bella("Bella");
	bella.takeDamage(1);
	bella.attack("Ufo");
	bella.beRepaired(1);
	std::cout << "---------------------------------------\n\n";

	std::cout << "----- Basic ScavTrap construction -----\n";
	ScavTrap scavBella("ScavBella");
	scavBella.beRepaired(1);
	scavBella.takeDamage(100);
	scavBella.attack("Ufo");
	scavBella.attack("Ufo");
	scavBella.guardGate();
	std::cout << "----------------------------------------\n\n";

	std::cout << "--------- Operator overloading ---------\n";
	ScavTrap donna("Donna");
	donna.beRepaired(1);
	donna.takeDamage(100);
	donna.attack("Ufo");
	donna.attack("Ufo");
	donna.guardGate();
	std::cout << "Calling the = operator overload for Donna.\n";
	donna = scavBella;
	donna.beRepaired(1);
	std::cout << "-----------------------------------------\n\n";

	return 0;
}
