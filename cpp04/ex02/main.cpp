/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 17:11:03 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/23 13:53:47 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "-------------Basic test-------------" << std::endl;
	const Animal* doggo = new Dog();
	const Animal* kitty = new Cat();

	std::cout << kitty->getType() << " " << std::endl;
	std::cout << doggo->getType() << " " << std::endl;
	doggo->makeSound();
	kitty->makeSound();

	delete kitty;
	delete doggo;
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "-------------Assignment test-------------" << std::endl;
	Dog doggo1;
	Dog doggo2 = doggo1;
	Dog doggo3 = Dog(doggo1);
	std::cout << "doggo 1 address: " << &doggo1 << std::endl;
	std::cout << "doggo 2 address: " << &doggo2 << std::endl;
	std::cout << "doggo 3 address: " << &doggo3 << std::endl;

	Cat kitty1;
	Cat kitty2 = kitty1;
	Cat kitty3 = Cat(kitty1);
	std::cout << "Kitty 1 address: " << &kitty1 << std::endl;
	std::cout << "Kitty 2 address: " << &kitty2 << std::endl;
	std::cout << "Kitty 3 address: " << &kitty3 << std::endl;

	std::cout << "---------Test non virtual-------\n";
	const WrongAnimal* wrongAnimal = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();
	const WrongCat* wrongCat1 = new WrongCat();
	std::cout << wrongAnimal->getType() << " " << std::endl;
	std::cout << wrongCat->getType() << " " << std::endl;
	std::cout << wrongCat1->getType() << " " << std::endl;
	wrongCat->makeSound(); //will output the animal sound!
	wrongCat1->makeSound(); //will output the animal sound!
	wrongAnimal->makeSound();
	std::cout << std::endl;

	delete wrongAnimal;
	delete wrongCat;
	delete wrongCat1;

	std::cout << std::endl;
	std::cout << "-------------Array test-------------" << std::endl;
	Animal *doggo4 = new Dog();
	Animal *kitty4 = new Cat();

	const Animal* animals[10] = {
		new Dog(),
		new Dog(),
		new Dog(),
		new Dog(),
		doggo4,
		new Cat(),
		new Cat(),
		new Cat(),
		new Cat(),
		kitty4
	};

	std::cout  << "-------------Array clean up-------------" << std::endl;
	for ( int i = 0; i < 10; i++ ) {
		delete animals[i];
		std::cout << std::endl;
	}

	std::cout  << "-------Static entity clean up--------" << std::endl;

	return 0;
}
