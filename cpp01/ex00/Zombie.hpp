/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 22:30:06 by meskelin          #+#    #+#             */
/*   Updated: 2023/09/05 13:18:21 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>
#include <iomanip>

class Zombie {
	private:
		std::string _name;

	public:
		Zombie(std::string name);
		~Zombie();

		void	announce(void);
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif
