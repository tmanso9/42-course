/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:50:41 by touteiro          #+#    #+#             */
/*   Updated: 2023/03/24 12:37:16 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->setType(type);
	std::cout << "Weapon constructor called" << std::endl;
}

Weapon::~Weapon()
{
	std::cout << "Weapon destructor called" << std::endl;
}

std::string const &	Weapon::getType(void)
{
	return (this->_type);
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
}
