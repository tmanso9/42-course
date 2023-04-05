/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:56:06 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/05 18:26:14 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice( void )
{
	this->type = "ice";
	std::cout << "Default ice constructor called" << std::endl;
}

Ice::Ice( Ice const & src) : AMateria(src)
{
	*this = src;
	std::cout << "Ice copy constructor called" << std::endl;
}

Ice::~Ice()
{
	std::cout << "Default ice destructor called" << std::endl;
}

Ice &	Ice::operator=( Ice const & src)
{
	this->type = src.getType();
	std::cout << "Ice assignment overload called" << std::endl;
	return *this;
}

Ice* Ice::clone() const
{
	Ice	*clone = new Ice();
	return clone;
}

void	Ice::use(ICharacter& target)
{
	if (!target.getName().size()) {
		std::cout << "Wrong target" << std::endl;
	} else {
		std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	}
}