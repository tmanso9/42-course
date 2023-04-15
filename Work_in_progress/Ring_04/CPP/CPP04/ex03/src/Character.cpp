/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:23:08 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/15 01:16:05 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character( void ) : ICharacter(), _name("")
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = 0;
	std::cout << "\033[0;32mCharacter default constructor called\033[0m" << std::endl;
}

Character::Character( Character const & src ) : ICharacter(src)
{
	*this = src;
	std::cout << "\033[0;32mCharacter copy constructor called\033[0m" << std::endl;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i])
			delete this->inventory[i];
	}
	std::cout << "\033[0;31mCharacter default destructor called\033[0m" << std::endl;
}

Character &	Character::operator=( Character const & src )
{
	for (int i = 0; i < 4; i++) {
		if (inventory[i])
			delete inventory[i];
		if (src.inventory[i]) {
			inventory[i] = src.inventory[i]->clone();
		} else {
			inventory[i] = NULL;
		}
	}
	return *this;
}

Character::Character( std::string name ) : ICharacter(), _name(name)
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	std::cout << "\033[0;32mCharacter with name as parameter constructor called\033[0m" << std::endl;
}

std::string  const & Character::getName() const
{
	return this->_name;
}

void	Character::equip(AMateria * m)
{
	if (!m) {
		std::cout << "Error trying to equip: empty materia" << std::endl;
		return ;
	}
	int	equipped = 0;
	for (int i = 0; i < 4; i++)
	{
		if (!equipped && !this->inventory[i])
		{
			this->inventory[i] = m;
			equipped = 1;
			std::cout << "Equipped " << m->getType() << " at slot " << i << std::endl;
		}
	}
	if (!equipped)
	{
		std::cout << "Error trying to equip: inventory full" << std::endl;
		delete m;
	}
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx > 3) {
		std::cout << "Error on unequip: " << idx << " is out of range" << std::endl;
	}
	else if (!this->inventory[idx]) {
		std::cout << "Error on unequip: " << idx << " is an empty slot" << std::endl;
	} else {
		std::cout << "Unequipped " << this->inventory[idx]->getType() << " at slot " << idx << std::endl;
		dropped.add(this->inventory[idx]);
		this->inventory[idx] = NULL;
	}
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3) {
		std::cout << "Error on use: " << idx << " is out of range" << std::endl;
	}
	else if (!this->inventory[idx]) {
		std::cout << "Error on use: " << idx << " is an empty slot" << std::endl;
	} else {
		this->inventory[idx]->use(target);
	}
}
