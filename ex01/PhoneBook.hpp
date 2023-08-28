/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:45:38 by meskelin          #+#    #+#             */
/*   Updated: 2023/08/28 15:52:37 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "Contact.hpp"
#include <iostream>

class PhoneBook {
	private:
		Contact _contacts[8];

	public:
		PhoneBook();
		~PhoneBook();
		void	add_contact(void);
		void	search_contact(void) const;
		int		display_contacts(void) const;
};

#endif
