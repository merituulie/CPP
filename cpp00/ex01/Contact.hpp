/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 12:26:42 by meskelin          #+#    #+#             */
/*   Updated: 2023/08/28 15:21:15 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

#include <string>
#include <iostream>
#include <iomanip>

class Contact {
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickName;
		std::string	_phoneNumber;
		std::string	_darkestSecret;
		int			_index;

	public:
		Contact();
		~Contact();

		void		init(int index);
		void		set_index(int index);

		void		display(void) const;
		void		view(void) const;
		int			get_index(void) const;
};

#endif
