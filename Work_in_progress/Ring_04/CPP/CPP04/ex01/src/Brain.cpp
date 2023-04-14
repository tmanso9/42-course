/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:00:00 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/14 20:28:03 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <cstring>

Brain::Brain( void )
{
	
	std::cout << "\033[0;36mBrain default constructor called\033[0m" << std::endl;
}

Brain::Brain( Brain const & src )
{
	std::cout << "\033[0;36mBrain copy constructor called\033[0m" << std::endl;
	*this = src;
}

Brain::~Brain()
{
	std::cout << "\033[0;31mBrain default destructor called\033[0m" << std::endl;
}

Brain &	Brain::operator=( Brain const & src )
{
	for (int i = 0; i < 100; i++) {
		this->ideas[i] = src.ideas[i];
	}
	return *this;
}
