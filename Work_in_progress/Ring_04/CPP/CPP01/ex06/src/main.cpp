/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 13:07:16 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/10 20:41:03 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	
	if (argc == 2)
	{
		Harl		h1;
		
		std::cout << std::endl;
		h1.complain(argv[1]);
	}
	else
	{
		std::cout << "Wrong number of arguments." << std::endl;
		std::cout << "Usage: ./harlFilter <level>" << std::endl;
	}
	
}