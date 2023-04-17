/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:13:05 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/14 22:12:52 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal( void ) : type("random animal")
{
	std::cout << "\033[0;32mAbstract animal default constructor called\033[0m]" << std::endl;
}

AAnimal::AAnimal( AAnimal const & src )
{
	*this = src;
	std::cout << "\033[0;32mAbstract animal copy constructor called\033[0m" << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "\033[0;31mAbstract animal default destructor called\033[0m" << std::endl;
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

void	AAnimal::setType( std::string word )
{
	type = word;
}

