/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:38:46 by touteiro          #+#    #+#             */
/*   Updated: 2023/03/23 16:40:40 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <new>

Zombie* newZombie( std::string name )
{
	Zombie *zomb = new Zombie(name);

	std::cout << "Returning NEW zombie" << std::endl;
	return (zomb);
}
