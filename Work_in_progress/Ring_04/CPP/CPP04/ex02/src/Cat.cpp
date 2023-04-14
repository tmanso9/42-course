/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:40:18 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/14 22:09:27 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void )
{
	setType("Cat");
	this->brain = new Brain();
	std::cout << "\033[0;32mI am a default new cat and I grace you with my presence\033[0m" << std::endl;
}

Cat::Cat( Cat const & src ) : AAnimal(src)
{
	*this = src;
	std::cout << "\033[0;32mI am a copy cat and I grace you with my presence\033[0m" << std::endl;
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << "\033[0;31mI am a cat and I have better things to do. Bye.\033[0m" << std::endl;
}

Cat &	Cat::operator=( Cat const & src )
{
	this->type = src.getType();
	brain = new Brain(src.getBrain());
	return *this;
}

void	Cat::makeSound( void ) const
{
	std::cout << "I am a cat and I'm too dignified to bark. Meow" << std::endl;
}

Brain &	Cat::getBrain( void ) const
{
	return (*this->brain);
}