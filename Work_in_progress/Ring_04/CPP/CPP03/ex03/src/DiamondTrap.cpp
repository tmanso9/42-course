/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 19:00:39 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/04 19:07:14 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ) : FragTrap(), ScavTrap()
{
	std::cout << "\033[0;32mDefault DiamondTrap constructor called\033[0m" << std::endl;
}

DiamondTrap::DiamondTrap( std::string name ) : ClapTrap(name), FragTrap(name), ScavTrap(name)
{
    std::cout << "\033[0;32mDiamondTrap constructor called for " << name << "\033[0m" << std::endl;
    this->_name = name;
	this->ClapTrap::_name = name + "_clap_name";
	// this->ScavTrap::_name = name;
	this->_hitPoints = FragTrap::getHitPoints();
	this->_energyPoints = ScavTrap::getEnergyPoints();
	this->_damage = FragTrap::getDamage();
}

DiamondTrap::~DiamondTrap()
{
	if (this->_name.size()) {
		std::cout << "\033[0;31mDiamondTrap destructor called for " << this->_name << "\033[0m" << std::endl;
	} else {
	std::cout << "\033[0;31mDiamondTrap destructor called\033[0m" << std::endl;
	}
}

void    DiamondTrap::whoAmI( void )
{
    std::cout << "Who am I? That is a great question..." << std::endl;
    std::cout << "My name is " << this->_name << std::endl;
    std::cout << "My ClapTrap name is " << this->ClapTrap::_name << std::endl;
    std::cout << "Is it clear now?" << std::endl << std::endl;
}

std::string DiamondTrap::getName( void )
{
    return this->_name;
}

int DiamondTrap::getDamage( void )
{
    return this->_damage;
}

int DiamondTrap::getHitPoints( void )
{
    return this->_hitPoints;
}

void    DiamondTrap::attack( const std::string & target)
{
    this->ScavTrap::attack(target);
}
