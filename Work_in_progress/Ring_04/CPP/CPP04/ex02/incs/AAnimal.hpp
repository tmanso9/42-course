/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 10:56:33 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/05 14:10:16 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal
{
protected:
	std::string	type;
public:
	AAnimal( void );
	AAnimal( AAnimal const & );
	virtual ~AAnimal();

	AAnimal & 		operator=( AAnimal const & );
	std::string		getType( void ) const;
	virtual void	makeSound( void ) const = 0;
};



#endif