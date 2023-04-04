/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:07:11 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/04 19:12:03 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	std::string	One = "One";
	std::string	Two = "Two";
	DiamondTrap	d1(One);
	DiamondTrap	d2(Two);

    d1.whoAmI();
    d2.whoAmI();
    std::cout << "I am " << d1.getName() << " and my hit points as a DiamondTrap are " << d1.getHitPoints() << std::endl;
    std::cout << "I am " << d2.getName() << " and my energy points as a DiamondTrap are " << d2.getEnergyPoints() << std::endl;
    std::cout << "I am " << d1.getName() << " and my damage points as a DiamondTrap are " << d1.getDamage() << std::endl << std::endl;
	std::cout << "Now for the interesting part:" << std::endl;
    d1.attack(Two);
	d2.takeDamage(d1.getDamage());
	d2.attack(One);
	d1.takeDamage(d2.getDamage());
	d2.beRepaired(15);
	d1.attack(Two);
	d2.takeDamage(d1.getDamage());
}