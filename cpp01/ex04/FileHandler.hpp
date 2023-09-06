/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileHandler.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 21:37:35 by meskelin          #+#    #+#             */
/*   Updated: 2023/09/06 21:40:10 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILEHANDLER_H
# define FILEHANDLER_H

#include <iostream>
#include <fstream>

class FileHandler {
	private:
		std::string _infile;
		std::string _outfile;

	public:
		FileHandler(std::string infile);
		~FileHandler();

		void	replace_occurences(std::string to_replace, std::string replace_with) const;
};

#endif
