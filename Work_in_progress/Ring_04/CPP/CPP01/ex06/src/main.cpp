/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 13:07:16 by touteiro          #+#    #+#             */
/*   Updated: 2023/03/25 17:12:08 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl		h1;
	
	if (argc == 2)
	{
		std::cout << std::endl;
		h1.complain(argv[1]);
	}
	else
		std::cout << "Wrong number of arguments!" << std::endl;
	
}