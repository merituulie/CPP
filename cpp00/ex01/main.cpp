/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:43:35 by meskelin          #+#    #+#             */
/*   Updated: 2023/08/28 17:58:00 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

std::string	read_selection()
{
	int			success = 0;
	std::string	input = "";

	do
	{
		std::cout << "Options:" << std::endl;
		std::cout << "ADD -> Add a new contact to your phone book." << std::endl;
		std::cout << "SEARCH -> Search for a specific contact." << std::endl;
		std::cout << "EXIT -> Exit the program." << std::endl;
		std::cout << "What would you like to do?: " << std::flush;
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

int main(void)
{
	int			input_l;
	std::string	input = "";
	PhoneBook	book;

	std::cout << std::endl;
	std::cout << "Welcome to the PhoneBook 1.0\n" << std::endl;
	while (1)
	{
		input = read_selection();
		input_l = input.length();
		if (input_l == 3 && input.compare("ADD") == 0)
		{
			book.add_contact();
			continue;
		}
		else if (input_l == 6 && input.compare("SEARCH") == 0)
		{
			if (book.display_contacts())
				book.search_contact();
			continue;
		}
		else if (input_l == 4 && input.compare("EXIT") == 0)
			break ;
		else
			std::cout << "No such option, please try again..." << std::endl;
	}

	return (0);
}
