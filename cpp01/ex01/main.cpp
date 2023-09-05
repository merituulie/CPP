/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 22:53:22 by meskelin          #+#    #+#             */
/*   Updated: 2023/09/05 16:29:53 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

static void	announce_zombies(Zombie *zombs, int n)
{
	int i = 0;
	while (i <= n)
		zombs[i++].announce();
}

int	main(void)
{
	Zombie *zombs;

	std::cout << "-------- TEST 1 --------" << std::endl;
	std::cout << "Creating -1 zombies..." << std::endl;
	zombs = zombieHorde(-1, "Negative");
	std::cout << "Deleting zombies..." << std::endl;
	std::cout << "------------------------" << std::endl;

	std::cout << "-------- TEST 2 --------" << std::endl;
	std::cout << "Creating 0 zombies..." << std::endl;
	zombs = zombieHorde(0, "None");
	std::cout << "Deleting zombies..." << std::endl;
	delete[] zombs;
	std::cout << "------------------------" << std::endl;

	std::cout << "-------- TEST 3 --------" << std::endl;
	std::cout << "Creating 3 zombies..." << std::endl;
	zombs = zombieHorde(3, "Jack");
	announce_zombies(zombs, 3);
	std::cout << "Deleting zombies..." << std::endl;
	delete[] zombs;
	std::cout << "------------------------" << std::endl;

	std::cout << "-------- TEST 4 --------" << std::endl;
	std::cout << "Creating 10 zombies..." << std::endl;
	zombs = zombieHorde(10, "Jane");
	announce_zombies(zombs, 9);
	std::cout << "Deleting zombies..." << std::endl;
	delete[] zombs;
	std::cout << "------------------------" << std::endl;

	std::cout << "-------- TEST 5 --------" << std::endl;
	std::cout << "Creating 100 zombies..." << std::endl;
	zombs = zombieHorde(100, "Jane");
	announce_zombies(zombs, 100);
	std::cout << "Deleting zombies..." << std::endl;
	delete[] zombs;
	std::cout << "------------------------" << std::endl;

	return 0;
}
