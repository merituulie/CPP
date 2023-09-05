/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:13:28 by meskelin          #+#    #+#             */
/*   Updated: 2023/09/05 16:25:37 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	if (N < 1)
	{
		std::cout << "Can't create less than 1 zombie for the horde." << std::endl;
		return NULL;
	}

	int i = 0;
	Zombie	*zombies = new Zombie[N];
	while (i < N)
		zombies[i++].set_name(name);

	return zombies;
}
