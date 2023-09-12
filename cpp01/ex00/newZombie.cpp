/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 22:42:10 by meskelin          #+#    #+#             */
/*   Updated: 2023/09/12 10:14:34 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	newZombie(std::string name)
{
	if (name.empty())
	{
		std::cout << "Please provide a name to the zombie..." << std::endl;
		return NULL;
	}

	return new Zombie(name);
}
