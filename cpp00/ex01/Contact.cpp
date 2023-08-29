#include "Contact.hpp"
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 12:26:29 by meskelin          #+#    #+#             */
/*   Updated: 2023/08/28 12:26:30 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
	this->_index = -1;
}

static std::string read_value(std::string output)
{
	int			success = 0;
	std::string	input = "";

	do {
		std::cout << output << std::flush;
		std::getline(std::cin, input);
		if (std::cin.eof())
			exit(0);
		if (std::cin.good() && !input.empty())
			success = 1;
		else
		{
			std::cin.clear();
			std::cout << "Invalid input, please try again..." << std::endl;
		}
	} while (!success);

	return (input);
}

void Contact::init(int index)
{
	std::cout << "Adding a new contact for the index " << index << std::endl;
	std::cout << "Please fill in the following information" << std::endl;
	this->_firstName = read_value("First name: ");
	this->_lastName = read_value("Last name: ");
	this->_nickName = read_value("Nickname: ");
	this->_phoneNumber = read_value("Phone number: ");
	this->_darkestSecret = read_value("Darkest secret: ");
	std::cout << "Adding a new contact succeeded!\n" << std::endl;
}

void Contact::set_index(int index)
{
	this->_index = index;
}

static std::string	get_max(std::string output)
{
	if (output.length() > 10)
		return output.substr(0, 9) + '.';
	return output;
}

void Contact::display(void) const
{
	if (this->_index == -1)
		return ;
	std::cout << "|" << std::setw(10) << this->_index << std::flush;
	std::cout << "|" << std::setw(10)<< get_max(this->_firstName) << std::flush;
	std::cout << "|" << std::setw(10)<< get_max(this->_lastName) << std::flush;
	std::cout << "|" << std::setw(10)<< get_max(this->_nickName) << "|" << std::flush;
	std::cout << std::endl;
}

void Contact::view(void) const
{
	if (this->_index == -1)
	{
		std::cout << "Nothing to see in this index, add new contacts!" << std::endl;
		return;
	}

	std::cout << "CONTACT #" << this->_index << std::endl;
	std::cout << "First name:\t" << this->_firstName << std::endl;
	std::cout << "Last name:\t" << this->_lastName << std::endl;
	std::cout << "Nickname:\t" << this->_nickName << std::endl;
	std::cout << "Phone number:\t" << this->_phoneNumber << std::endl;
	std::cout << "Darkest secret:\t" << this->_darkestSecret << "\n" << std::endl;
}

int Contact::get_index(void) const
{
	return this->_index;
}

std::string Contact::get_firstname(void) const
{
	return this->_firstName;
}

std::string Contact::get_lastname(void) const
{
	return this->_lastName;
}

std::string Contact::get_nickname(void) const
{
	return this->_nickName;
}

std::string Contact::get_phonenumber(void) const
{
	return this->_phoneNumber;
}

std::string Contact::get_darkest_secret(void) const
{
	return this->_darkestSecret;
}
