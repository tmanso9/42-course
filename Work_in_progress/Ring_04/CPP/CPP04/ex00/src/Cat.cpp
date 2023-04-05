/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:40:18 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/05 11:50:12 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void )
{
	this->type = "Cat";
	std::cout << "I am a default new cat and I grace you with my presence" << std::endl;
}

Cat::Cat( Cat const & src ) : Animal(src)
{
	*this = src;
	std::cout << "I am a copy cat and I grace you with my presence" << std::endl;
}

Cat::~Cat()
{
	std::cout << "I am a cat and I have better things to do. Bye." << std::endl;
}

Cat &	Cat::operator=( Cat const & src )
{
	this->type = src.getType();
	return *this;
}

void	Cat::makeSound( void ) const
{
	std::cout << "I am a cat and I'm too dignified to bark. Meow" << std::endl;
}