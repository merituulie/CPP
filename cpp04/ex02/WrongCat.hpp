/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:13:13 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/21 16:25:41 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_H
# define WRONGCAT_H

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		~WrongCat(void);
		WrongCat(void);
		WrongCat(const WrongCat& rhs);

		WrongCat& operator=(const WrongCat& rhs);

		void	makeSound() const;
};

#endif
