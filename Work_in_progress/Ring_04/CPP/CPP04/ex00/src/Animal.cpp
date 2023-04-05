/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:13:05 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/05 11:26:51 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal( void ) : type("random animal")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal( Animal const & src )
{
	*this = src;
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal default destructor called" << std::endl;
}

Animal & Animal::operator=( Animal const & src )
{
	this->type = src.getType();
	return *this;
}

std::string	Animal::getType( void ) const
{
	return type;
}

void	Animal::makeSound( void ) const
{
	std::cout << "I am a random animal and I make random noises" << std::endl;
}
