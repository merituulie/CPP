#include "PhoneBook.hpp"
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:50:14 by meskelin          #+#    #+#             */
/*   Updated: 2023/08/28 13:50:17 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	int i = 0;

	while (i < 8)
		this->_contacts[i++].set_index(-1);
}

PhoneBook::~PhoneBook(void)
{
}

void	PhoneBook::add_contact(void)
{
	static int	i;

	this->_contacts[i % 8].set_index(i % 8);
	this->_contacts[i % 8].init(i % 8);
	i++;
}

static int read_index(void)
{
	int		input = -1;
	bool	valid = false;

	do
	{
		std::cout << "Please enter the contact index: " << std::flush;
		std::cin >> input;
		if (std::cin.eof())
			exit(0);
		if (std::cin.good() && (input >= 0 && input <= 7)) {
			valid = true;
		} else {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "You can only search between 0 and 7, please try again..." << std::endl;
		}
	} while (!valid);
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	return (input);
}

void	PhoneBook::search_contact(void) const
{
	int		index;

	std::cin.clear();
	index = read_index();
	std::cout << std::endl;
	this->_contacts[index].view();
}

int	PhoneBook::display_contacts(void) const
{
	int	i = 0;

	while (i < 8)
	{
		if (this->_contacts[i].get_index() == -1)
		{
			if (i == 0)
			{
				std::cout << "No contacts to search for, please add some...\n" << std::endl;
				return (0);
			}
			else
			{
				i++;
				continue;
			}
		}
		this->_contacts[i++].display();
	}
	std::cout << std::endl;

	return (1);
}
