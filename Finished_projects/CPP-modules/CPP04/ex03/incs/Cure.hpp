/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:45:54 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/05 18:06:05 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #pragma once
#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"


class Cure : public AMateria
{
public:
	Cure( void );
	Cure( Cure const & );
	~Cure();
	Cure & operator=( Cure const & );

	virtual Cure*	clone() const;
	virtual void	use(ICharacter& target);
};

#endif