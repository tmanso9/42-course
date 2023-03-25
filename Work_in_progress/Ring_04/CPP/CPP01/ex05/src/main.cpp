/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 13:07:16 by touteiro          #+#    #+#             */
/*   Updated: 2023/03/25 16:34:55 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl		h1;
	std::string	msgs[6];
	msgs[0] = "debug";
	msgs[1] = "info";
	msgs[2] = "warning";
	msgs[3] = "error";
	msgs[4] = "hello";
	msgs[5] = "";

	std::cout << std::endl;
	
	for (int i = 0; i < 6; i++)
		h1.complain(msgs[i]);

	std::cout << std::endl;
}