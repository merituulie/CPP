/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 20:39:09 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/16 20:53:23 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap bella("Bella");
	bella.attack("Spaceship");
	bella.attack("Ufo");
	bella.attack("Neighbour");
	bella.attack("The crazy aunt");
	bella.attack("Bear");
	bella.attack("Enemy");
	bella.attack("Murderer");
	bella.attack("Scarecrow");
	bella.attack("Spaceship");
	bella.attack("Ufo");
	bella.attack("Sniper"); // Should fail, as there is no energy

	bella.takeDamage(1);
	bella.takeDamage(100); // Health should stay in 0

	bella.beRepaired(10); // Should fail, as there is no energy

	ClapTrap donna("Donna");
	donna.attack("Bella");
	donna.beRepaired(100);
}
