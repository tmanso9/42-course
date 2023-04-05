/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:28:58 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/05 17:43:31 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #pragma once
#ifndef IMATERIASOURCE_SPP
# define IMATERIASOURCE_SPP

# include "AMateria.hpp"
// # include "Ice.hpp"
// # include "Cure.hpp"

class IMateriaSource
{
public:
	virtual ~IMateriaSource();
	virtual void	learnMateria( AMateria* ) = 0;
	virtual AMateria *	createMateria(std::string const & type) = 0;
};

#endif