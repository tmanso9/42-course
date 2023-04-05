/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:48:28 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/05 18:09:37 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria( void ) : type("abstract")
{
	std::cout << "Default abstract materia constructor called" << std::endl;
}

AMateria::AMateria( AMateria const & src ) : type("abstract")
{
	*this = src;
	std::cout << "Abstract materia copy constructor called" << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "Default abstract materia destructor called" << std::endl;
}

AMateria & AMateria::operator=( AMateria const & src)
{
	this->type = src.getType();
	std::cout << "Abstract assignment overload called" << std::endl;
	return *this;
}

AMateria::AMateria(std::string const & type)
{
	this->type = type;
}

std::string const & AMateria::getType() const
{
	return this->type;
}

void	AMateria::use(ICharacter& target)
{
	std::cout << "bla attack " << target.getName() << std::endl;
}

