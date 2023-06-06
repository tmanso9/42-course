/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replaceStrings.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 22:28:33 by touteiro          #+#    #+#             */
/*   Updated: 2023/03/25 12:32:12 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

void	replaceStrings(std::ifstream *infile, std::ofstream *outfile, std::string toFind, std::string toReplace)
{
	int linesRead = 0;
	std::string	str;
	while (std::getline(*infile, str))
	{
		if (linesRead)
			*outfile << std::endl;
		linesRead++;

		int	i = str.find(toFind);
		while (i >= 0)
		{
			*outfile << str.substr(0, i);
			str.erase(0, i);
			*outfile << toReplace;
			str.erase(0, toFind.size());
			i = str.find(toFind);
		}

		*outfile << str;
	}
}