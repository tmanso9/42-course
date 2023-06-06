/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:56:06 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/14 22:28:45 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure( void )
{
	this->type = "cure";
	std::cout << "\033[0;32mDefault cure constructor called\033[0m" << std::endl;
}

Cure::Cure( Cure const & src) : AMateria(src)
{
	*this = src;
	std::cout << "\033[0;32mCure copy constructor called\033[0m" << std::endl;
}

Cure::~Cure()
{
	std::cout << "\033[0;31mDefault cure destructor called\033[0m" << std::endl;
}

Cure &	Cure::operator=( Cure const & src)
{
	this->type = src.getType();
	std::cout << "\033[0;32mCure assignment overload called\033[0m" << std::endl;
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