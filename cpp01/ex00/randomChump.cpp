/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 22:50:59 by meskelin          #+#    #+#             */
/*   Updated: 2023/09/04 22:55:54 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void    randomChump(std::string name)
{
	if (name.empty())
	{
		std::cout << "Please provide a name to the zombie..." << std::endl;
		return;
	}

    Zombie zombi(name);
    zombi.announce();
}
