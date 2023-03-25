/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 13:07:16 by touteiro          #+#    #+#             */
/*   Updated: 2023/03/25 14:00:02 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	std::cout << "Hello!" << std::endl;
	Harl	h1;
	std::cout << std::endl;
	h1.complain("0");
	std::cout << std::endl;
	h1.complain("1");
	std::cout << std::endl;
	h1.complain("2");
	std::cout << std::endl;
	h1.complain("3");
	std::cout << std::endl;
	h1.complain("9");
	std::cout << std::endl;
	h1.complain("ajdhvfjhvs");
}