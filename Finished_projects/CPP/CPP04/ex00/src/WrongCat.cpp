/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 19:13:20 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/17 14:19:46 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "\033[0;32mTHIS IS NOT A CAT\033[0m" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "\033[0;31mWrong cat going away\033[0m" << std::endl;
}

WrongCat::WrongCat( WrongCat const & src ) : WrongAnimal(src)
{
	*this = src;
}

WrongCat & WrongCat::operator=( WrongCat const & src )
{
	setType(src.getType());
	return *this;
}

void	WrongCat::makeSound( void ) const
{
	std::cout << "Meow?" << std::endl;
}