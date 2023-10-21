/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 20:56:21 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/21 12:39:15 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_H
# define CLAP_TRAP_H

#include <iostream>

class ClapTrap {
	private:
	protected:
		ClapTrap(void);

		std::string	_name;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;

	public:
		~ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& rhs);

		ClapTrap& operator=(const ClapTrap& rhs);

		virtual void attack(const std::string& target);
		virtual void takeDamage(unsigned int amount);
		virtual void beRepaired(unsigned int amount);
};

#endif
