/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:02:48 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/03 16:31:12 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>

class ClapTrap
{
private:
	std::string _name;
	int	_hitPoints;
	int	_energyPoints;
	int	_damage;
	
public:
	ClapTrap( void );
	ClapTrap( std::string name );
	ClapTrap( ClapTrap const & src);
	~ClapTrap();

	ClapTrap &	operator=( ClapTrap const & src );
	void	setName( std::string name );
	std::string	getName( void ) const;
	int	getHitPoints( void ) const;
	int	getEnergyPoints( void ) const;
	int	getDamage( void ) const;

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif