/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:07:11 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/03 17:27:14 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	a;
	ClapTrap	b("Luis");
	ClapTrap	c("Afonso");
	
	a = c;
	b.attack(a.getName());
	a.takeDamage(9);
	a.beRepaired(3);
	b.attack(a.getName());
	a.takeDamage(25);
	a.attack(b.getName());
	a.beRepaired(3);
}