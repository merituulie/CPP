/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 11:17:10 by meskelin          #+#    #+#             */
/*   Updated: 2023/08/29 16:01:54 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

static void	print_upper_string(unsigned char **argv)
{
	int i = 1;

	while (argv[i])
	{
		int j = 0;
		while (argv[i][j])
			std::cout << ((char)toupper(argv[i][j++]));
		i++;
	}
	std::cout << std::endl;
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
		print_upper_string((unsigned char **)argv);
	return (0);
}
