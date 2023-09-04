/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 22:53:22 by meskelin          #+#    #+#             */
/*   Updated: 2023/09/04 22:58:15 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"



int main(void)
{
    std::cout << "Creating zombie on the heap." << std::endl;
    Zombie *cran = newZombie("Cranberry");
    cran->announce();
    delete cran;

    std::cout << "Creating zombie on the stack." << std::endl;
    randomChump("Randomberry");

    return 0;
}
