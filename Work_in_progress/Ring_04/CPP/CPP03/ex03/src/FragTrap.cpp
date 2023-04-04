/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 18:31:31 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/04 18:47:47 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_damage = 30;
	std::cout << "\033[0;32mDefault FragTrap constructor called\033[0m" << std::endl;
}

FragTrap::FragTrap( std::string name)
{
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_damage = 30;
	std::cout << "\033[0;32mFragTrap constructor called for " << name << "\033[0m" << std::endl;
}

FragTrap::FragTrap( FragTrap const & src)
{
	*this = src;
}

FragTrap::~FragTrap()
{
	if (this->getName().size()) {
		std::cout << "\033[0;31mFragTrap destructor called for " << this->getName() << "\033[0m" << std::endl;
	} else {
	std::cout << "\033[0;31mFragTrap destructor called\033[0m" << std::endl;
	}
}

FragTrap & FragTrap::operator=( FragTrap const & src )
{
	std::cout << "\033[0;32mFragTrap copy assignment operator called for " << src.getName() << "\033[0m" << std::endl;
	this->_name = src.getName();
	this->_hitPoints = src.getHitPoints();
	this->_energyPoints = src.getEnergyPoints();
	this->_damage = src.getDamage();
	return (*this);
}

void	FragTrap::highFivesGuys( void )
{
	std::cout << this->getName() << " wants to high five you." << std::endl;
}

int	FragTrap::getDamage( void ) const
{
	return 30;
}

int	FragTrap::getHitPoints( void ) const
{
	return 100;
}