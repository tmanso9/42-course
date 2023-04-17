/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 18:49:48 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/14 19:17:20 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) : type("I am wrong")
{
	std::cout << "\033[0;32mWrongAnimal constructor called\033[0m" << std::endl;
}

WrongAnimal::WrongAnimal( WrongAnimal const & src )
{
	*this = src;
}

WrongAnimal & WrongAnimal::operator=( WrongAnimal const & src )
{
	this->type = src.getType();
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "\033[0;31mWrongAnimal destructor called\033[0m" << std::endl;
}

std::string	WrongAnimal::getType( void ) const
{
	return type;
}

void	WrongAnimal::setType( std::string newType )
{
	type = newType;
}

void	WrongAnimal::makeSound( void ) const
{
	std::cout << "My sound is all wrong" << std::endl;
}