/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:07:11 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/17 14:25:32 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	{
		const Animal* meta = new Animal();
		const Animal* i = new Dog();
		const Animal* j = new Cat();
		const WrongAnimal*	w = new WrongCat();
		const WrongCat*		z = new WrongCat();
		
		std::cout << std::endl << "Printing types: " << std::endl;
		std::cout << meta->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		std::cout << j->getType() << " " << std::endl;
		std::cout << w->getType() << " " << std::endl;
		std::cout << z->getType() << " " << std::endl;
		
		std::cout << std::endl << "Making sounds: " << std::endl;
		std::cout << "Dog: ";
		i->makeSound();
		std::cout << "Cat: ";
		j->makeSound();
		std::cout << "Wrong cat in WrongAnimal body: ";
		w->makeSound();
		std::cout << "Wrong cat: ";
		z->makeSound();
		std::cout << "Random: ";
		meta->makeSound();

		delete meta;
		delete j;
		delete i;
		delete w;
		delete z;
	}
}