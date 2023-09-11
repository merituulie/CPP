/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 21:32:00 by meskelin          #+#    #+#             */
/*   Updated: 2023/09/11 19:39:53 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

void	replace(std::string	input, char **argv)
{
	std::ofstream	outfile;
	outfile.open((std::string(argv[1]) + ".replace").c_str());
	if (outfile.fail())
	{
		std::cerr << "Error when opening the file" << std::endl;
		return ;
	}

	int length = (int)input.length();
	for (int i = 0; i < length; i++)
	{
		int	position = input.find(argv[2], i);
		if (position == i)
		{
			outfile << argv[3];
			i += std::string(argv[2]).size() - 1;
		}
		else
			outfile << input[i];
	}
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

	std::ifstream	infile;
	infile.open(argv[1]);
	if (infile.fail())
	{
		std::cerr << "Error when opening the file" << std::endl;
		return (1);
	}

	char c;
	std::string	input;
	while(!infile.eof() && infile >> std::noskipws >> c)
		input += c;
	infile.close();
	replace(input, argv);

	return (0);
}
