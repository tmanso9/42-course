/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 13:07:16 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/10 20:19:59 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl		harl;
	std::string	msgs[7];
	msgs[0] = "DEBUG";
	msgs[1] = "INFO";
	msgs[2] = "WARNING";
	msgs[3] = "ERROR";
	msgs[4] = "info";
	msgs[5] = "hello";
	msgs[6] = "";

	for (int i = 0; i < 7; i++)
		harl.complain(msgs[i]);

}