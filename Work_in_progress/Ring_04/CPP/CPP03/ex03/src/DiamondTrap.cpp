/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 19:00:39 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/03 19:28:52 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void )
{
	std::cout << "\033[0;32mDefault DiamondTrap constructor called\033[0m" << std::endl;
}

DiamondTrap::DiamondTrap( std::string name )
{
	this->_name = ClapTrap(name).getName() + "_clap_name";
	std::cout << "\033[0;32mDiamondTrap constructor called for " << this->_name << "\033[0m" << std::endl;
	this->_hitPoints = FragTrap::getHitPoints();
	std::cout << this->_hitPoints << std::endl;
	this->setEnergyPoints(100);
	this->setDamage(30);
}

DiamondTrap::~DiamondTrap()
{
	if (this->_name.size()) {
		std::cout << "\033[0;31mDiamondTrap destructor called for " << this->_name << "\033[0m" << std::endl;
	} else {
	std::cout << "\033[0;31mDiamondTrap destructor called\033[0m" << std::endl;
	}
}