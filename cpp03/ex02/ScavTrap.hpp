/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 12:57:52 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/21 13:42:04 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAV_TRAP_H
# define SCAV_TRAP_H

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:
		bool _isGuarding;

	public:
		~ScavTrap(void);
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& rhs);

		ScavTrap& operator=(const ScavTrap& rhs);

		void	attack(const std::string& target);
		void	guardGate(void);
};

#endif
