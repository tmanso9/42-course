/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:13:05 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/14 19:05:11 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal( void ) : type("random animal")
{
	std::cout << "\033[0;32mAnimal default constructor called\033[0m" << std::endl;
}

Animal::Animal( Animal const & src )
{
	*this = src;
	std::cout << "\033[0;32mAnimal copy constructor called\033[0m" << std::endl;
}

Animal::~Animal()
{
	std::cout << "\033[0;31mAnimal default destructor called\033[0m" << std::endl;
}

Animal & Animal::operator=( Animal const & src )
{
	this->type = src.getType();
	return *this;
}

void	Animal::setType( std::string word )
{
	type = word;
}


std::string	Animal::getType( void ) const
{
	return type;
}

void	Animal::makeSound( void ) const
{
	std::cout << "I am a random animal and I make random noises" << std::endl;
}
