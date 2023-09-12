/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 21:32:00 by meskelin          #+#    #+#             */
/*   Updated: 2023/09/12 11:33:46 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

void	replace(char **argv)
{
	std::string		input_file = (std::string)argv[1];

	std::ifstream	infile;
	infile.open(input_file);
	if (infile.fail())
	{
		std::cerr << "Error when opening the file" << std::endl;
		return ;
	}

	std::ofstream	outfile;
	outfile.open(input_file + ".replace");
	if (outfile.fail())
	{
		std::cerr << "Error when opening the file" << std::endl;
		return ;
	}

	std::string	temp;
	std::string	to_replace = (std::string)argv[2];
	size_t		to_replace_l = to_replace.length();
	while (std::getline(infile, temp))
	{
		size_t pos = temp.find(to_replace);
		while (pos != std::string::npos)
		{
			temp.replace(pos, to_replace_l, argv[3]);
			pos = temp.find(to_replace, pos += to_replace_l);
		}
		outfile << temp << "\n";
	}
	infile.close();
	outfile.close();
}

int main(int argc, char **argv)
{
	if (argc < 4 || argc > 4)
	{
		std::cerr << "Expected the following input: <filename> <word_to_replace> <word_to_replace_with>" << std::endl;
		return (1);
	}

	if (argv[1][0] == '\0' || argv[1][0] == '\n'
		|| argv[2][0] == '\0' || argv[2][0] == '\n'
		|| argv[3][0] == '\0' || argv[3][0] == '\n')
	{
		std::cerr << "The values <filename>, <word_to_replace>, <word_to_replace_with> can't be empty" << std::endl;
		return (1);
	}
	replace(argv);
	return (0);
}
