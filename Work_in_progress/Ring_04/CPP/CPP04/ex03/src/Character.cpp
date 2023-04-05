/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:23:08 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/05 18:52:06 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character( void ) : _name("")
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = 0;
	std::cout << "Character default constructor called" << std::endl;
}

Character::Character( Character const & src )
{
	*this = src;
	std::cout << "Character copy constructor called" << std::endl;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i])
			delete this->inventory[i];
	}
	std::cout << "Character default destructor called" << std::endl;
}

Character &	Character::operator=( Character const & src )
{
	*this = Character(src);
	return *this;
}

Character::Character( std::string name ) : _name(name)
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = 0;
	std::cout << "Character named constructor called" << std::endl;
}

std::string  const & Character::getName() const
{
	return this->_name;
}

void	Character::equip(AMateria * m)
{
	if (!m)
		return ;
	int	equipped = 0;
	for (int i = 0; i < 4; i++)
	{
		if (!equipped && !this->inventory[i])
		{
			this->inventory[i] = m;
			equipped = 1;
			std::cout << "equipped " << m->getType() << " at slot " << i << std::endl;
		}
	}
	if (!equipped)
	{
		std::cout << "Inventory full" << std::endl;
		delete m;
	}
}

void	Character::unequip(int idx)
{
	if (this->inventory[idx]) {
		std::cout << "Unequipped " << this->inventory[idx]->getType() << " at slot " << idx << std::endl;
		dropped.add(this->inventory[idx]);
		this->inventory[idx] = 0;
	} else {
		std::cout << "Slot empty" << std::endl;
	}
}

void	Character::use(int idx, ICharacter& target)
{
	if (this->inventory[idx]) {
		this->inventory[idx]->use(target);
	} else {
		std::cout << "Impossible action" << std::endl;
	}
}
