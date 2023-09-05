/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 22:53:22 by meskelin          #+#    #+#             */
/*   Updated: 2023/09/05 13:16:32 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"



int main(void)
{
    std::cout << "Creating a zombie on the heap." << std::endl;
    Zombie *cran = newZombie("Cranberry");
    cran->announce();
    delete cran;

    std::cout << "Creating a zombie on the stack." << std::endl;
    randomChump("Randomberry");

    return 0;
}
