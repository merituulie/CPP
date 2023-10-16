/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 20:04:38 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/16 20:50:00 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_H
# define CLAP_TRAP_H

#include <iostream>

class ClapTrap {
	private:
		const std::string	_name;
		int					_hitPoints;
		int					_energyPoints;
		int					_attackDamage;
		static const int	_totalHitPoints = 10;

		ClapTrap(void);

	public:
		~ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& rhs);

		ClapTrap& operator=(const ClapTrap& rhs);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif
