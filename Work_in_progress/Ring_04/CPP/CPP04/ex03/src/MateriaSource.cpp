/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:36:30 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/05 18:27:56 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource( void )
{
	std::cout << "MaterialSource default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->addresses[i] = 0;
}

MateriaSource::MateriaSource( MateriaSource const & src )
{
	*this = src;
	std::cout << "MaterialSource copy constructor called" << std::endl;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->addresses[i])
			delete this->addresses[i];
	}
	std::cout << "MaterialSource destructor called" << std::endl;
}

MateriaSource &	MateriaSource::operator=( MateriaSource const & src )
{
	*this = MateriaSource(src);
	return *this;
}

void	MateriaSource::learnMateria( AMateria *src )
{
	int	learned = 0;
	for (int i = 0; i < 4; i++)
	{
		if (!learned && !this->addresses[i])
		{
			this->addresses[i] = src;
			learned = 1;
		}
	}
	if (!learned)
	{
		std::cout << "Memory full" << std::endl;
		delete src;
	}
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->addresses[i] && !type.compare(this->addresses[i]->getType()))
			return this->addresses[i]->clone();
	}
	std::cout << "Unknown materia" << std::endl;
	return 0;
}
