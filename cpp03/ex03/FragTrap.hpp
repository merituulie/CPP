/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 13:24:14 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/23 12:05:46 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAG_TRAP_H
# define FRAG_TRAP_H

#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{
	protected:
		FragTrap(void);

	public:
		~FragTrap(void);
		FragTrap(std::string name);
		FragTrap(const FragTrap& rhs);

		FragTrap& operator=(const FragTrap& rhs);

		void	highFivesGuys(void);
};

#endif
