/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:28:23 by meskelin          #+#    #+#             */
/*   Updated: 2023/09/12 11:50:36 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main()
{
	{
		Weapon club = Weapon("");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some weapon");
		bob.attack();
	}
	{
		HumanB jim("Jim");
		jim.attack();
		Weapon club = Weapon("crude spiked club");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}

	return 0;
}
