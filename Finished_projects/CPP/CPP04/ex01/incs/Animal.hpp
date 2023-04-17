/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 10:56:33 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/14 20:39:38 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
protected:
	std::string	type;
public:
	Animal( void );
	Animal( Animal const & );
	virtual ~Animal();

	Animal & 		operator=( Animal const & );
	std::string		getType( void ) const;
	void		setType( std::string );
	virtual void	makeSound( void ) const;
};



#endif