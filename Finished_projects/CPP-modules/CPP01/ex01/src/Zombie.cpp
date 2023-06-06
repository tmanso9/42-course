/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:38:48 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/10 19:15:37 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	std::cout << "\033[0;32mZombie constructor called\033[0m" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "\033[0;31mZombie destructor called for " << this->_name << ".\033[0m" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::addName(std::string name)
{
	this->_name = name;
}