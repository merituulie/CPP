/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:05:10 by meskelin          #+#    #+#             */
/*   Updated: 2023/09/05 17:13:02 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	std::string brain = "HI THIS IS BRAIN";
	std::string *stringPTR = &brain;
	std::string &stringREF = brain;

	std::cout << "string address:\t\t\t" << &brain << std::endl;
	std::cout << "pointer points to address:\t" << stringPTR << std::endl;
	std::cout << "reference points to address:\t" << &stringREF << std::endl;

	std::cout << "\nstring value:\t\t\t" << brain << std::endl;
	std::cout << "pointer points to value:\t" << *stringPTR << std::endl;
	std::cout << "reference points to value:\t" << stringREF << std::endl;
}
