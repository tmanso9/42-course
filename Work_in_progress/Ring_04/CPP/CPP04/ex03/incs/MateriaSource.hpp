/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:34:40 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/05 17:21:14 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #pragma once
#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria	*addresses[4];
public:
	MateriaSource( void );
	~MateriaSource();
	MateriaSource( MateriaSource const & );
	MateriaSource &	operator=( MateriaSource const & );

	virtual void	learnMateria( AMateria* );
	virtual AMateria*	createMateria(std::string const & type);
};


#endif