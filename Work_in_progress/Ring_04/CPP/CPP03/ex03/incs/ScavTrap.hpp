/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:30:13 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/14 13:44:40 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap
{
public:
	ScavTrap();
	ScavTrap( std::string );
	ScavTrap( ScavTrap const &);
	~ScavTrap();

	ScavTrap & operator=( ScavTrap const & );
	void	guardGate();
	void	attack(const std::string& target);
};

#endif