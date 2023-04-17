/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:07:11 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/13 18:22:29 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap	blert("Blert");
	ScavTrap	Forty("Fortytuos");
	ScavTrap	c = blert;

	blert.attack(Forty.getName());
	Forty.takeDamage(blert.getDamage());
	blert.attack(Forty.getName());
	Forty.takeDamage(blert.getDamage());
	Forty.guardGate();
	Forty.beRepaired(15);
	blert.attack(Forty.getName());
	Forty.takeDamage(blert.getDamage());
	blert.attack(Forty.getName());
	Forty.takeDamage(blert.getDamage());
	blert.attack(Forty.getName());
	Forty.takeDamage(blert.getDamage());
	blert.attack(Forty.getName());
	Forty.takeDamage(blert.getDamage());
	
}