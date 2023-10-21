/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:28:56 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/21 16:45:48 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main(void)
{
	std::cout << "---------Test virtual-------\n";
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	std::cout << meta->getType() << " " << std::endl;
	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	cat->makeSound(); //will output the cat sound!
	dog->makeSound();
	meta->makeSound();
	std::cout << std::endl;
	delete meta;
	delete dog;
	delete cat;
	std::cout << "----------------------------\n\n";


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
	std::cout << "--------------------------------\n\n";


	return 0;
}
