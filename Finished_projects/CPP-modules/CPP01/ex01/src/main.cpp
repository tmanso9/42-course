/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:31:02 by touteiro          #+#    #+#             */
/*   Updated: 2023/03/25 16:43:27 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name );

int	main(void)
{
	int	N = 15;
	Zombie	*horde = zombieHorde(N, "We are a horde");
	for (int i = 0; i < N; i++)
	{
		std::cout << i << ": ";
		horde[i].announce();
	}
	
	delete [] horde;
}