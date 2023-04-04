/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 18:42:55 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/04 18:32:54 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap: public FragTrap, public ScavTrap
{
private:
	std::string	_name;
public:
	DiamondTrap( void );
	DiamondTrap( std::string );
	~DiamondTrap();

	void	    whoAmI( void );
	std::string	getName( void );
	int     	getDamage( void );
	int			getHitPoints( void );
	// std::string	getName( void );
	// std::string	getName( void );
    void        attack( const std::string & target);
};



#endif