/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 18:42:55 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/14 18:09:44 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	DiamondTrap( DiamondTrap const & );
	~DiamondTrap( void );

	DiamondTrap & operator=( DiamondTrap const & );
	void	    whoAmI( void );
	std::string	getName( void ) const;
    void        attack( const std::string & target);
};



#endif