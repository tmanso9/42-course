/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:38:48 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/10 19:54:03 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( std::string name ) : _name(name)
{
	std::cout << "\033[0;32mZombie " << this->_name << " constructor called\033[0m" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "\033[0;31mZombie " << this->_name << " destructor called\033[0m" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}