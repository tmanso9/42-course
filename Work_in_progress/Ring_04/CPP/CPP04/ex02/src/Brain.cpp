/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:00:00 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/05 12:13:48 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <cstring>

Brain::Brain( void )
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain( Brain const & src )
{
	*this = src;
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain default destructor called" << std::endl;
}

Brain &	Brain::operator=( Brain const & src )
{
	*this = Brain(src);
	return *this;
}
