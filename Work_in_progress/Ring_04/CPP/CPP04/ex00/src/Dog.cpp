/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:29:25 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/14 19:05:25 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void )
{
	setType("Dog");
	std::cout << "\033[0;32mDefault new dog jumps up and down with joy\033[0m" << std::endl;
}

Dog::Dog( Dog const & src ) : Animal(src)
{
	*this = src;
	std::cout << "\033[0;32mCopy dog jumps up and down with joy\033[0m" << std::endl;
}

Dog::~Dog()
{
	std::cout << "\033[0;31mDog gone to search for treats\033[0m" << std::endl;
}

Dog &	Dog::operator=(Dog const & src)
{
	this->type = src.getType();
	return *this;
}

void	Dog::makeSound( void ) const
{
	std::cout << "I'm a happy dog and I say Woof woof" << std::endl;
}