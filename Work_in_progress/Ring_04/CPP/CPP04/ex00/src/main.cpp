/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:07:11 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/14 19:19:36 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		const WrongAnimal*	w = new WrongCat();
		std::cout << meta->getType() << " " << std::endl;
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		std::cout << w->getType() << " " << std::endl;
		std::cout << "Dog: ";
		i->makeSound(); //will output the cat sound!
		std::cout << "Cat: ";
		j->makeSound();
		std::cout << "Wrong cat: ";
		w->makeSound();
		std::cout << "Random: ";
		meta->makeSound();

		delete meta;
		delete j;
		delete i;
		delete w;
	}
}