/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:13:05 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/05 12:47:53 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal( void ) : type("random animal")
{
	std::cout << "Abstract animal default constructor called" << std::endl;
}

AAnimal::AAnimal( AAnimal const & src )
{
	*this = src;
	std::cout << "Abstract animal copy constructor called" << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "Abstract animal default destructor called" << std::endl;
}

AAnimal & AAnimal::operator=( AAnimal const & src )
{
	this->type = src.getType();
	return *this;
}

std::string	AAnimal::getType( void ) const
{
	return type;
}

