/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:50:41 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/10 19:23:41 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->setType(type);
	std::cout << "\033[0;32mWeapon constructor called\033[0m" << std::endl;
}

Weapon::~Weapon()
{
	std::cout << "\033[0;31mWeapon destructor called\033[0m" << std::endl;
}

std::string const &	Weapon::getType(void)
{
	return (this->_type);
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
}
