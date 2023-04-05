/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:27:15 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/05 11:36:12 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
protected:
	/* data */
public:
	Dog( void );
	Dog(Dog const &);
	virtual ~Dog();

	Dog &	operator=(Dog const &);
	virtual void	makeSound( void ) const;
};



#endif