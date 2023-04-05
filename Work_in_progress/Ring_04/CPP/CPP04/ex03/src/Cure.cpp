/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:56:06 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/05 18:23:54 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure( void )
{
	this->type = "cure";
	std::cout << "Default cure constructor called" << std::endl;
}

Cure::Cure( Cure const & src) : AMateria(src)
{
	*this = src;
	std::cout << "Cure copy constructor called" << std::endl;
}

Cure::~Cure()
{
	std::cout << "Default cure destructor called" << std::endl;
}

Cure &	Cure::operator=( Cure const & src)
{
	// this->type = src.getType();
	(void)src;
	std::cout << "Cure assignment overload called" << std::endl;
	return *this;
}

Cure* Cure::clone() const
{
	Cure	*clone = new Cure();
	return clone;
}

void	Cure::use(ICharacter& target)
{
	if (!target.getName().size()) {
		std::cout << "Wrong target" << std::endl;
	} else {
		std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
	}
}