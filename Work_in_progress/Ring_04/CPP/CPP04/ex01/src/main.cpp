/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:07:11 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/05 12:23:56 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main(void)
{
	const	Animal*	bunch[10];
	for (int i = 0; i < 10; i++)
	{
		if (i % 2)
			bunch[i] = new Dog();
		else
			bunch[i] = new Cat();
	}
	for (int i = 0; i < 10; i++)
	{
		bunch[i]->makeSound();
	}
	for (int i = 0; i < 10; i++)
		delete bunch[i];
}