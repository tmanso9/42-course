/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:29:25 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/05 12:14:45 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void )
{
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "Default new dog jumps up and down with joy" << std::endl;
}

Dog::Dog( Dog const & src ) : Animal(src)
{
	*this = src;
	std::cout << "Copy dog jumps up and down with joy" << std::endl;
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "Dog gone to search for treats" << std::endl;
}

Dog &	Dog::operator=(Dog const & src)
{
	this->type = src.getType();
	this->brain = src.getBrain();
	return *this;
}

void	Dog::makeSound( void ) const
{
	std::cout << "I'm a happy dog and I say Woof woof" << std::endl;
}

Brain	*Dog::getBrain( void ) const
{
	return this->brain;
}