/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:03:27 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/13 18:10:26 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void ) : _hitPoints(10), _energyPoints(10), _damage(0)
{
	std::cout << "\033[0;32mDefault ClapTrap constructor called\033[0m" << std::endl;
}

ClapTrap::ClapTrap( std::string name ) : _hitPoints(10), _energyPoints(10), _damage(0)
{
	this->setName(name);
	std::cout << "\033[0;32mClapTrap constructor called for " << name << "\033[0m" << std::endl;
}

ClapTrap::ClapTrap( ClapTrap const & src ) : _hitPoints(10), _energyPoints(10), _damage(0)
{
	*this = src;
	std::cout << "\033[0;32mCopy constructor called for " << this->_name << "\033[0m" << std::endl;
}

ClapTrap &	ClapTrap::operator=(ClapTrap const & src)
{
	std::cout << "\033[0;32mClapTrap copy assignment operator called for " << src.getName() << "\033[0m" << std::endl;
	this->setName( src.getName() );
	this->setHitPoints(src.getHitPoints());
	this->setEnergyPoints(src.getEnergyPoints());
	this->setDamage(src.getDamage());
	return (*this);
}

ClapTrap::~ClapTrap()
{
	if (this->_name.size()) {
		std::cout << "\033[0;31mClapTrap destructor called for " << this->_name << "\033[0m" << std::endl;
	} else {
		std::cout << "\033[0;31mDestructor called\033[0m" << std::endl;
	}
}

void	ClapTrap::setName( std::string name )
{
	this->_name = name;
}

void	ClapTrap::setHitPoints( int hitPoints )
{
	this->_hitPoints = hitPoints;
}

void	ClapTrap::setEnergyPoints( int energyPoints )
{
	this->_energyPoints = energyPoints;
}

void	ClapTrap::setDamage( int damage )
{
	this->_damage = damage;
}

std::string	ClapTrap::getName( void ) const
{
	return (this->_name);
}

int	ClapTrap::getHitPoints( void ) const
{
	return (this->_hitPoints);
}

int	ClapTrap::getEnergyPoints( void ) const
{
	return (this->_energyPoints);
}

int	ClapTrap::getDamage( void ) const
{
	return (this->_damage);
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_energyPoints && this->_hitPoints) {
		this->_energyPoints--;
		std::cout << "ClapTrap " << this->getName() << " attacks " << target << ", causing " << this->_damage << " points of damage!" << std::endl;
	} else if (!this->_hitPoints) {
		std::cout << "ClapTrap " << this->getName() << " is dead and can't attack " << target << "." << std::endl; 
	} else {
		std::cout << "ClapTrap " << this->getName() << " doesn't have enough energy points to attack." << std::endl; 
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints) {
		this->_hitPoints -= amount;
		if (this->_hitPoints < 0) {
			this->_hitPoints = 0;
			std::cout << "ClapTrap " << this->getName() << " took " << amount << " points of damage and died." << std::endl;
		} else {
			std::cout << "ClapTrap " << this->getName() << " took " << amount << " points of damage, now has " << this->_hitPoints << " points." << std::endl;
		}
	} else {
		std::cout << "ClapTrap " << this->getName() << " is already dead." << std::endl; 
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints && this->_hitPoints) {
		this->_energyPoints--;
		this->_hitPoints += amount;
		std::cout << "ClapTrap " << this->getName() << " repaired itself and got " << amount << " points back. Now has " << this->_hitPoints << " points." << std::endl;
	} else if (!this->_hitPoints) {
		std::cout << "ClapTrap " << this->getName() << " is dead and can't repair itself." << std::endl; 
	}  else {	
		std::cout << "ClapTrap " << this->getName() << " doesn't have enough energy points to repair itself." << std::endl; 
	}
}

