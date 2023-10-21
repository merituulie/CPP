/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:13:13 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/21 16:15:50 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
# define CAT_H

#include "Animal.hpp"

class Cat : public Animal
{
	public:
		~Cat(void);
		Cat(void);
		Cat(const Cat& rhs);

		Cat& operator=(const Cat& rhs);

		void	makeSound() const;
};

#endif
