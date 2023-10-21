/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 20:58:06 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/21 12:46:40 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAV_TRAP_H
# define SCAV_TRAP_H

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:
		bool	_isGuarding;

		ScavTrap(void);
	public:
		~ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &rhs);

		ScavTrap &operator=(const ScavTrap &rhs);

		void	guardGate();
		void	attack(const std::string& target);
};

#endif
