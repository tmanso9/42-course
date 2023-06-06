/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:27:15 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/14 20:22:13 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain	*brain;
public:
	Dog( void );
	Dog(Dog const &);
	virtual ~Dog();

	Dog &			operator=(Dog const &);
	virtual void	makeSound( void ) const;
	Brain	&		getBrain( void ) const;
};



#endif