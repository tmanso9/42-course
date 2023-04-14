/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 18:31:31 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/14 18:25:50 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap( void )
{
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setDamage(30);
	std::cout << "\033[0;32mDefault FragTrap constructor called\033[0m" << std::endl;
}

FragTrap::FragTrap( std::string name)
{
	this->setName(name);
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setDamage(30);
	std::cout << "\033[0;32mFragTrap constructor called for " << name << "\033[0m" << std::endl;
}

FragTrap::FragTrap( FragTrap const & src) : ClapTrap(src)
{
	*this = src;
}

FragTrap::~FragTrap( void )
{
	std::cout << "\033[0;31mFragTrap destructor called for " << this->getName() << "\033[0m" << std::endl;
}

FragTrap & FragTrap::operator=( FragTrap const & src )
{
	this->setName( src.getName() );
	this->setHitPoints(src.getHitPoints());
	this->setEnergyPoints(src.getEnergyPoints());
	this->setDamage(src.getDamage());
	std::cout << "\033[0;32mFragTrap copy assignment operator called for " << src.getName() << "\033[0m" << std::endl;

	return (*this);
}


void	FragTrap::highFivesGuys( void )
{
	std::cout << this->getName() << " wants to high five you." << std::endl;
}