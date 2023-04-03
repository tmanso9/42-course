/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:07:11 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/03 18:50:51 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	FragTrap	a("Blert");
	FragTrap	b("Fortytuos");
	FragTrap	c = a;
	ScavTrap	d("Dynamo");

	a.attack(b.getName());
	b.takeDamage(a.getDamage());
	a.attack(b.getName());
	b.takeDamage(a.getDamage());
	b.highFivesGuys();
	b.beRepaired(15);
	a.attack(b.getName());
	b.takeDamage(a.getDamage());
	b.attack(d.getName());
	d.takeDamage(b.getDamage());
	b.attack(d.getName());
	d.takeDamage(b.getDamage());
	b.attack(d.getName());
	d.takeDamage(b.getDamage());
	d.attack(a.getName());
	a.takeDamage(d.getDamage());
	b.attack(d.getName());
	d.takeDamage(b.getDamage());
	b.attack(d.getName());
	d.takeDamage(b.getDamage());
}