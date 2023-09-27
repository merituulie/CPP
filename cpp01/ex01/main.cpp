/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 22:53:22 by meskelin          #+#    #+#             */
/*   Updated: 2023/09/12 10:20:26 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

static void	announce_zombies(Zombie *zombs, int n)
{
	int i = 0;
	while (i <= n)
		zombs[i++].announce();
}

static void	test_create_horde(int tst, int zmbs, std::string name)
{
	Zombie *zombs;

	std::cout << "-------- TEST " << tst << " --------" << std::endl;
	std::cout << "Creating " << zmbs << " zombies..." << std::endl;

	zombs = zombieHorde(zmbs, name);

	if (zmbs > 0)
	{
		announce_zombies(zombs, zmbs - 1);
		std::cout << "Deleting zombies..." << std::endl;
		delete[] zombs;
	}

	std::cout << "------------------------" << std::endl;
}

int	main(void)
{
	int i = 1;

	test_create_horde(i++, -1, "Negative");
	test_create_horde(i++, 0, "None");
	test_create_horde(i++, 10, "Jane");
	test_create_horde(i++, 100, "Jane");

	return 0;
}
