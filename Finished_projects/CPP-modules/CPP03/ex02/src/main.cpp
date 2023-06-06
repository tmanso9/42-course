/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:07:11 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/13 18:28:52 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	FragTrap	Blert("Blert");
	FragTrap	Forty("Fortytuos");
	FragTrap	c = Blert;
	ScavTrap	Dynamo("Dynamo");

	Blert.attack(Forty.getName());
	Forty.takeDamage(Blert.getDamage());
	Blert.attack(Forty.getName());
	Forty.takeDamage(Blert.getDamage());
	Forty.highFivesGuys();
	Forty.beRepaired(15);
	Blert.attack(Forty.getName());
	Forty.takeDamage(Blert.getDamage());
	Forty.attack(Dynamo.getName());
	Dynamo.takeDamage(Forty.getDamage());
	Forty.attack(Dynamo.getName());
	Dynamo.takeDamage(Forty.getDamage());
	Forty.attack(Dynamo.getName());
	Dynamo.takeDamage(Forty.getDamage());
	Dynamo.attack(Blert.getName());
	Blert.takeDamage(Dynamo.getDamage());
	Forty.attack(Dynamo.getName());
	Dynamo.takeDamage(Forty.getDamage());
	Forty.attack(Dynamo.getName());
	Dynamo.takeDamage(Forty.getDamage());
}