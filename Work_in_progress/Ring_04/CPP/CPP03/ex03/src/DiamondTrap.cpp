/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 19:00:39 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/14 13:57:11 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ) : FragTrap(), ScavTrap()
{
	std::cout << "\033[0;32mDefault DiamondTrap constructor called\033[0m" << std::endl;
}

DiamondTrap::DiamondTrap( std::string name ) : ClapTrap(name + "_clap_name"), FragTrap(), ScavTrap(), _name(name)
{
	FragTrap::_hitPoints = 100;
	ScavTrap::_energyPoints = 50;
	FragTrap::_damage = 30;
    std::cout << "\033[0;32mDiamondTrap constructor called for " << name << "\033[0m" << std::endl;
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
    return _name;
}

void    DiamondTrap::attack( const std::string & target)
{
    ScavTrap::attack(target);
}
