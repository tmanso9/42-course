/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:07:11 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/03 18:01:17 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap	a("Blert");
	ScavTrap	b("Fortytuos");
	ScavTrap	c = a;

	a.attack(b.getName());
	b.takeDamage(a.getDamage());
	a.attack(b.getName());
	b.takeDamage(a.getDamage());
	b.guardGate();
	b.beRepaired(15);
	a.attack(b.getName());
	b.takeDamage(a.getDamage());
}