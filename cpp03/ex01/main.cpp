/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 21:13:16 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/16 21:48:31 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap bella("Bella");
	bella.takeDamage(1);
	bella.attack("Ufo");
	bella.beRepaired(1);

	ScavTrap donna(bella);
	donna.beRepaired(1);
	donna.takeDamage(100);
	donna.attack("Ufo");
	donna.attack("Ufo");
	donna.guardGate();

	return 0;
}
