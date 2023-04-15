/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:48:28 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/14 22:29:51 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria( void ) : type("abstract")
{
	std::cout << "\033[0;32mDefault abstract materia constructor called\033[0m" << std::endl;
}

AMateria::AMateria( AMateria const & src ) : type("abstract")
{
	*this = src;
	std::cout << "\033[0;32mAbstract materia copy constructor called\033[0m" << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "\033[0;31mDefault abstract materia destructor called\033[0m" << std::endl;
}

AMateria & AMateria::operator=( AMateria const & src)
{
	std::cout << "\033[0;32mAbstract assignment overload called\033[0m" << std::endl;
	this->type = src.getType();
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

