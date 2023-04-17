/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:02:48 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/14 14:00:10 by touteiro         ###   ########.fr       */
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
	ClapTrap( std::string );
	ClapTrap( ClapTrap const & );
	~ClapTrap( void );

	ClapTrap &	operator=( ClapTrap const & );
	
	void	setName( std::string );
	void	setHitPoints( int );
	void	setEnergyPoints( int );
	void	setDamage( int );
	
	std::string	getName( void ) const;
	int	getHitPoints( void ) const;
	int	getEnergyPoints( void ) const;
	int	getDamage( void ) const;

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif