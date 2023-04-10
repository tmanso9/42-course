/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 12:07:10 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/10 19:32:18 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): _weapon(weapon)
{
	std::cout << name << " constructor called." << std::endl;
	this->_name = name;
}

HumanA::~HumanA()
{
	std::cout << this->_name << " destructor called." << std::endl;
}

void	HumanA::attack(void)
{
	if (this->_weapon.getType().empty())
		std::cout << "Error! " << this->_name << " needs a weapon to attack with." << std::endl;
	else
		std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}