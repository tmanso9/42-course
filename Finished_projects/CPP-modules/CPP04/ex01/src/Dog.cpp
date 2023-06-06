/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:29:25 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/14 20:28:25 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void )
{
	setType("Dog");
	brain = new Brain;
	std::cout << "\033[0;32mDefault new dog jumps up and down with joy\033[0m" << std::endl;
}

Dog::Dog( Dog const & src ) : Animal(src)
{
	*this = src;
	std::cout << "\033[0;32mCopy dog jumps up and down with joy\033[0m" << std::endl;
}

Dog::~Dog()
{
	delete brain;
	std::cout << "\033[0;31mDog gone to search for treats\033[0m" << std::endl;
}

Dog &	Dog::operator=(Dog const & src)
{
	type = src.getType();
	brain = new Brain(src.getBrain());
	return *this;
}

void	Dog::makeSound( void ) const
{
	std::cout << "I'm a happy dog and I say Woof woof" << std::endl;
}

Brain &	Dog::getBrain( void ) const
{
	return *(this->brain);
}