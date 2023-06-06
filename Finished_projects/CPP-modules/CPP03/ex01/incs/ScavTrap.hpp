/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:30:13 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/13 18:18:29 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	
public:
	ScavTrap( void );
	ScavTrap( std::string );
	ScavTrap( ScavTrap const &);
	~ScavTrap( void );

	ScavTrap & operator=( ScavTrap const & );
	void	guardGate();
	void	attack(const std::string& target);
};

#endif