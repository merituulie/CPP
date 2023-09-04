/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 22:35:43 by meskelin          #+#    #+#             */
/*   Updated: 2023/09/04 22:41:52 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name)
{
}

Zombie::~Zombie()
{
	std::cout << this->_name << "is destroyed." << std::endl;
}

void Zombie::announce(void)
{
	if (this->_name.empty())
		return;
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
