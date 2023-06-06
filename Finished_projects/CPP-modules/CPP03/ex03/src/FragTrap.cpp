/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 18:31:31 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/14 14:02:21 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    _hitPoints = 100;
	_energyPoints = 100;
	_damage = 30;
	std::cout << "\033[0;32mDefault FragTrap constructor called\033[0m" << std::endl;
}

FragTrap::FragTrap( std::string name )
{
	_name = name;
	_hitPoints = 100;
	_energyPoints = 100;
	_damage = 30;
	std::cout << "\033[0;32mFragTrap constructor called for " << name << "\033[0m" << std::endl;
}

FragTrap::FragTrap( FragTrap const & src) : ClapTrap(src)
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
