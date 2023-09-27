/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 22:30:06 by meskelin          #+#    #+#             */
/*   Updated: 2023/09/12 10:17:08 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>

class Zombie {
	private:
		std::string _name;

	public:
		Zombie();
		~Zombie();

		void	set_name(std::string name);
		void	announce(void);
};

Zombie* zombieHorde(int N, std::string name);

#endif
