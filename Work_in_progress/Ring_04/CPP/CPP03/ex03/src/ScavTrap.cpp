/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:29:43 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/03 19:05:13 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "\033[0;32mDefault ScavTrap constructor called\033[0m" << std::endl;
}

ScavTrap::ScavTrap( std::string name)
{
	this->setName(name);
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setDamage(20);
	std::cout << "\033[0;32mScavTrap constructor called for " << name << "\033[0m" << std::endl;
}

ScavTrap::ScavTrap( ScavTrap const & src)
{
	*this = src;
}

ScavTrap::~ScavTrap()
{
	if (this->getName().size()) {
		std::cout << "\033[0;31mScavTrap destructor called for " << this->getName() << "\033[0m" << std::endl;
	} else {
	std::cout << "\033[0;31mScavTrap destructor called\033[0m" << std::endl;
	}
}

ScavTrap & ScavTrap::operator=( ScavTrap const & src )
{
	this->setName( src.getName() );
	this->setHitPoints(src.getHitPoints());
	this->setEnergyPoints(src.getEnergyPoints());
	this->setDamage(src.getDamage());
	std::cout << "\033[0;32mScavTrap copy assignment operator called for " << src.getName() << "\033[0m" << std::endl;

	return (*this);
}


void	ScavTrap::guardGate( void )
{
	std::cout << this->getName() << " is now in Gate keeper mode." << std::endl;
}