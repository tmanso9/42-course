/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:27:24 by touteiro          #+#    #+#             */
/*   Updated: 2023/03/22 18:27:38 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv){
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; i < argc ; i++)
	{
		std::string	str = argv[i];
		for (unsigned int j = 0; j < str.size(); j++)
			std::cout << (unsigned char)std::toupper(*(str.begin() + j));
	}
	std::cout << std::endl;
}
