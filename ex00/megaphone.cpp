/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 11:17:10 by meskelin          #+#    #+#             */
/*   Updated: 2023/08/28 11:53:04 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

static void print_upper_char(unsigned char c)
{
	if (isalpha(c))
		std::cout << (char)toupper(c);
	else
		std::cout << (char)c;
}

static void	print_upper_string(int argc, unsigned char **argv)
{
	int i = 1;
	char c = '\0';

	while (argv[i])
	{
		int j = 0;
		while (argv[i][j])
		{
			if (isspace(argv[i][j]) && isspace(c))
			{
				j++;
				continue ;
			}
			c = argv[i][j++];
			print_upper_char(c);
		}
		if (i < (argc - 1) && !isspace(c))
		{
			c = ' ';
			std::cout << ' ';
		}
		i++;
	}
	std::cout << std::endl;
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
		print_upper_string(argc, (unsigned char **)argv);
	return (0);
}
