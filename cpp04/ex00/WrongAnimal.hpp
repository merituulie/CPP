/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:57:41 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/21 16:26:33 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_H
# define WRONGANIMAL_H

#include <iostream>

class WrongAnimal
{
	protected:
		std::string	type;

	public:
		~WrongAnimal(void);
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal& rhs);

		WrongAnimal& operator=(const WrongAnimal& rhs);

		void			makeSound() const;
		std::string		getType() const;
};

#endif
