/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:14:42 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/05 18:12:45 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #pragma once
#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include <iostream>
# include <string>
// # include "MateriaSource.hpp"
# include "AMateria.hpp"
// # include "Ice.hpp"
// # include "Cure.hpp"

class	AMateria;

class ICharacter
{
public:
	virtual 		~ICharacter();
	virtual std::string  const & getName() const = 0;
	virtual void	equip(AMateria* m) = 0;
	virtual void	unequip(int idx) = 0;
	virtual void	use(int idx, ICharacter& target) = 0;
};

#endif