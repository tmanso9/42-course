/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:07:11 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/14 22:11:37 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main(void)
{
	const AAnimal*	dog = new Dog();
	const AAnimal*	cat = new Cat();
	// The next example doesn't compile because class is abstract
	// const AAnimal*	other = new AAnimal();

	dog->makeSound();
	cat->makeSound();
	delete dog;
	delete cat;
}