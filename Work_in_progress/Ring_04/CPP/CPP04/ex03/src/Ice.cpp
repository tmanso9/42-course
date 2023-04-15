/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:56:06 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/14 22:35:09 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice( void )
{
	this->type = "ice";
	std::cout << "\033[0;32mDefault ice constructor called\033[0m" << std::endl;
}

Ice::Ice( Ice const & src) : AMateria(src)
{
	*this = src;
	std::cout << "\033[0;32mIce copy constructor called\033[0m" << std::endl;
}

Ice::~Ice()
{
	std::cout << "\033[0;31mDefault ice destructor called\033[0m" << std::endl;
}

Ice &	Ice::operator=( Ice const & src)
{
	std::cout << "\033[0;32mIce assignment overload called\033[0m" << std::endl;
	this->type = src.getType();
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