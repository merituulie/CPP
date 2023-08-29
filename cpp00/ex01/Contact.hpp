/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 12:26:42 by meskelin          #+#    #+#             */
/*   Updated: 2023/08/29 15:55:08 by meskelin         ###   ########.fr       */
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

		std::string	get_firstname(void) const;
		std::string	get_lastname(void) const;
		std::string	get_nickname(void) const;
		std::string	get_phonenumber(void) const;
		std::string	get_darkest_secret(void) const;
		void		display(void) const;
		void		view(void) const;
		int			get_index(void) const;
};

#endif
