/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:07:11 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/17 14:45:04 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main(void)
{
	{
		const	Animal*	bunch[6];
		for (int i = 0; i < 6; i++)
		{
			if (i % 2)
				bunch[i] = new Dog();
			else
				bunch[i] = new Cat();
		}
		for (int i = 0; i < 6; i++)
		{
			std::cout << i << ": ";
			bunch[i]->makeSound();
		}
		for (int i = 0; i < 6; i++)
			delete bunch[i];
	}
	{
		std::cout << std::endl << "Checking the copy constructors: " << std::endl;
		const 	Dog*	dog = new Dog;
		const	Animal* other = new Dog(*dog);
		dog->makeSound();
		other->makeSound();
		delete dog;
		delete other;
	}
}