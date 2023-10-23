/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 13:24:14 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/23 12:06:24 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAG_TRAP_H
# define FRAG_TRAP_H

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	private:
		FragTrap(void);

	public:
		~FragTrap(void);
		FragTrap(std::string name);
		FragTrap(const FragTrap& rhs);

		FragTrap& operator=(const FragTrap& rhs);

		void	highFivesGuys(void);
};

#endif
