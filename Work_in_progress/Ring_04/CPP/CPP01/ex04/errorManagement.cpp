/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorManagement.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 19:13:08 by touteiro          #+#    #+#             */
/*   Updated: 2023/03/24 19:42:02 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	wrongArguments(void)
{
	std::cout << "Error: Wrong number of arguments." << std::endl;
	std::cout << "Usage: ./replace <filename> <string 1> <string2>" << std::endl;
	return 1;
}

int	noInFile(std::string file)
{
	std::cout << "Error: File '" << file << "' not found." << std::endl;
	return 1;
}

int	outFileErr(std::string file)
{
	std::cout << "Error: could not open or create '" << file << "'." << std::endl;
	return 1;
}