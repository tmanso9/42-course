/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:36:30 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/15 01:18:33 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource( void )
{
	std::cout << "\033[0;32mMateriaSource default constructor called\033[0m" << std::endl;
	for (int i = 0; i < 4; i++)
		this->addresses[i] = NULL;
}

MateriaSource::MateriaSource( MateriaSource const & src )
{
	*this = src;
	std::cout << "\033[0;32mMateriaSource copy constructor called\033[0m" << std::endl;
}

MateriaSource::~MateriaSource()
{
	std::cout << "\033[0;31mMateriaSource destructor called\033[0m" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->addresses[i])
			delete this->addresses[i];
	}
}

MateriaSource &	MateriaSource::operator=( MateriaSource const & src )
{
	for (int i = 0; i < 4; i++) {
		if (src.addresses[i])
			addresses[i] = src.addresses[i]->clone();
	}
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
		std::cout << "Error learning materia: memory full" << std::endl;
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
	std::cout << "Error creating Materia '" << type << "': unknown materia" << std::endl;
	return 0;
}
