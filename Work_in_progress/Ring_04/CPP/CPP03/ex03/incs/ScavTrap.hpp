/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:30:13 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/04 18:51:47 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap
{
private:
	/* data */
public:
	ScavTrap();
	ScavTrap( std::string );
	ScavTrap( ScavTrap const &);
	~ScavTrap();

	ScavTrap & operator=( ScavTrap const & );
	void	guardGate();
	void	attack(const std::string& target);
	int		getEnergyPoints() const;
	std::string	getName( void ) const;
};

#endif