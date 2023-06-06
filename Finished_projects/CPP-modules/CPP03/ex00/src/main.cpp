/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:07:11 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/13 18:10:43 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	a;
	ClapTrap	b("Marvin");
	ClapTrap	c("Phelps");
	
	a = c;
	b.attack(a.getName());
	a.takeDamage(9);
	a.beRepaired(3);
	b.attack(a.getName());
	a.takeDamage(25);
	a.attack(b.getName());
	a.beRepaired(3);
}