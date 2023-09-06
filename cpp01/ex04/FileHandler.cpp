/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileHandler.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 21:40:20 by meskelin          #+#    #+#             */
/*   Updated: 2023/09/06 22:12:21 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileHandler.hpp"

FileHandler::FileHandler(std::string infile) : _infile(infile)
{
	if (this->_infile.empty())
	{
		std::cerr << "The file to read from can't be empty." << std::endl;
		return ;
	}

	this->_outfile = this->_infile;
	this->_outfile += ".replace";
}

FileHandler::~FileHandler()
{
}

void FileHandler::replace_occurences(std::string to_replace, std::string replace_with) const
{
	if (to_replace.empty() || replace_with.empty())
	{
		std::cerr << "Neither of the input strings can be empty." << std::endl;
		return ;
	}

	std::ifstream	instream(this->_infile);
	if (!instream.is_open())
	{
		std::cerr << "Error occured while opening the infile." << std::endl;
		return;
	}

	std::string file_content;
	if (std::getline(instream, file_content, '\0'))
	{
		std::ofstream	outstream(this->_outfile);
		size_t			index = file_content.find(to_replace);
		while (index != std::string::npos)
		{
			file_content.erase(index, to_replace.length());
			file_content.insert(index, replace_with);
			file_content.find(to_replace);
		}
		outstream << file_content;
		outstream.close();
	}
	else
	{
		std::cerr << "Empty file, no occurencces replaced." << std::endl;
	}
	instream.close();
}
