/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:52:17 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/21 16:56:20 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
# define BRAIN_H

#include <iostream>

class Brain
{
	private:
		std::string	ideas[100];

	public:
		Brain(void);
		~Brain(void);
		Brain(const Brain& rhs);

		Brain& operator=(const Brain& rhs);
};

#endif
