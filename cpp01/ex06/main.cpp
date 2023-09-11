/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 21:32:00 by meskelin          #+#    #+#             */
/*   Updated: 2023/09/11 20:18:15 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

static std::string	levels[4] =
{
	"DEBUG",
	"INFO",
	"WARNING",
	"ERROR"
};

static int convert_log_level(char *input)
{
	for (int i = 0; i < 4; i++)
	{
		if (input == levels[i])
			return (i);
	}
	return (-1);
}

int main(int argc, char **argv)
{
	if (argc < 2 || argc > 2 || (argv[1] && argv[1][0] == '\0'))
	{
		std::cerr << "[ Probably complaining about insignificant problems ]" << std::endl;
		return (1);
	}

	Harl harl;

	harl.complain("");
	switch (convert_log_level(argv[1]))
	{
		case 0:
			harl.complain(levels[0]);
			break ;
		case 1:
			harl.complain(levels[1]);
			break ;
		case 2:
			harl.complain(levels[2]);
			break ;
		case 3:
			harl.complain(levels[3]);
			break ;
		default:
			std::cerr << "[ Probably complaining about insignificant problems ]" << std::endl;
	}

	return (0);
}
