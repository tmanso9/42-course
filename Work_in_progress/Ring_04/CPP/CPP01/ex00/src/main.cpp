/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:37:10 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/10 17:01:38 by touteiro         ###   ########.fr       */
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
	std::cout << std::endl;

	std::cout << "Now, we'll create random zombies" << std::endl;
	randomChump("Riley");
	std::cout << std::endl;
	randomChump("Sam");
	std::cout << std::endl;
	randomChump("Tess");
	std::cout << std::endl;

	std::cout << "We can still announce the NEW zombie" << std::endl;
	zomb->announce();
	delete	zomb;
}
