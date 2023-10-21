/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:56:30 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/21 17:31:41 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain default constructor called.\n";
}

Brain::~Brain(void)
{
	std::cout << "Brain deconstructor called.\n";
}

Brain::Brain(const Brain& rhs)
{
	std::cout << "Brain copy constructor called.\n";
	*this = rhs;
}

Brain& Brain::operator=(const Brain& rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = rhs.ideas[i];
	}

	return *this;
}
