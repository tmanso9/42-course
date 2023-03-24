/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replaceStrings.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 22:28:33 by touteiro          #+#    #+#             */
/*   Updated: 2023/03/24 22:35:54 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

void	replaceStrings(std::ifstream *infile, std::ofstream *outfile, std::string toFind, std::string toReplace)
{
	std::string	str;
	while (std::getline(*infile, str))
	{
		int	i = str.find_first_of(*toFind.begin());
		while (i >= 0)
		{
			*outfile << str.substr(0, i);
			str.erase(0, i);
			if (!str.find(toFind))
			{
				*outfile << toReplace;
				str.erase(0, toFind.size());
			}
			i = str.find_first_of(*toFind.begin(), 1);
		}
		*outfile << str << std::endl;
	}
}