/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:27:15 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/14 22:09:02 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef DOG_HPP
# define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
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