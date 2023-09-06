/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 21:32:00 by meskelin          #+#    #+#             */
/*   Updated: 2023/09/06 22:06:01 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileHandler.hpp"

int main(int argc, char **argv)
{
	if (argc < 4 || argc > 4)
	{
		std::cerr << "Expected input: <filename> <string to find> <string to replace with>." << std::endl;
		return (1);
	}
	FileHandler handler(argv[1]);
	handler.replace_occurences(argv[2], argv[3]);

	return (0);
}
