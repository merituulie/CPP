/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 14:00:20 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/21 15:07:02 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMOND_TRAP_H
# define DIAMONG_TRAP_H

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string	_name;

		DiamondTrap(void);
	public:
		~DiamondTrap(void);
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap& rhs);

		DiamondTrap& operator=(const DiamondTrap& rhs);

		using	ScavTrap::attack;
		void	whoAmI();
};

#endif
