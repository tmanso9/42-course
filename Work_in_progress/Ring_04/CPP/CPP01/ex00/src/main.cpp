/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:37:10 by touteiro          #+#    #+#             */
/*   Updated: 2023/03/23 16:43:22 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie( std::string name );
void	randomChump( std::string name );

int	main(void)
{
	std::cout << "We will create a NEW zombie" << std::endl;
	Zombie	*zomb = newZombie("Newest");
	std::cout << "We will now announce this NEW zombie" << std::endl;
	zomb->announce();
	delete	zomb;

	std::cout << "We will create a random zombie" << std::endl;
	randomChump("Random");
	randomChump("Ellie");
	randomChump("Joel");
}
