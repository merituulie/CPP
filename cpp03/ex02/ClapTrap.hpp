/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 12:52:45 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/21 13:22:22 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_H
# define CLAP_TRAP_H

#include <iostream>

class ClapTrap {
	protected:
		std::string			_name;
		int					_hitPoints;
		int					_energyPoints;
		int					_attackDamage;

	public:
		ClapTrap(void);
		~ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& rhs);

		ClapTrap& operator=(const ClapTrap& rhs);

		virtual void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif
