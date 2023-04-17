/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:09:52 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/14 22:16:34 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include "ICharacter.hpp"
#include <iostream>
#include <string>

class	ICharacter;

class AMateria
{
protected:
	std::string type;
public:
	AMateria( void );
	AMateria( AMateria const & );
	virtual ~AMateria();
	AMateria & operator=( AMateria const &);

	AMateria(std::string const & type);
	std::string const & getType() const;

	virtual AMateria* clone() const = 0;
	virtual void use( ICharacter& target );
};

#endif