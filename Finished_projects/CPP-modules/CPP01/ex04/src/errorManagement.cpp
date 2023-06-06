/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorManagement.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 19:13:08 by touteiro          #+#    #+#             */
/*   Updated: 2023/03/24 22:50:04 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

int	wrongArguments(void)
{
	std::cout << "Error: Wrong number of arguments." << std::endl;
	std::cout << "Usage: ./replace <filename> <string 1> <string2>" << std::endl;
	return 1;
}

int	emptyArgs(void)
{
	std::cout << "Error: Arguments can't be empty." << std::endl;
	return 1;
}

int	noInFile(std::string file)
{
	std::cout << "Error: File '" << file << "' not valid." << std::endl;
	return 1;
}

int	outFileErr(std::string file)
{
	std::cout << "Error: could not open or create '" << file << "'." << std::endl;
	return 1;
}