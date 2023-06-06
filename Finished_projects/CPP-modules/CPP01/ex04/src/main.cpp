/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 12:47:52 by touteiro          #+#    #+#             */
/*   Updated: 2023/03/24 22:49:20 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

int main (int argc, char**argv)
{
	if (argc == 4)
	{
		std::string	filename = argv[1];
		std::string	toFind = argv[2];
		std::string	toReplace = argv[3];
		
		if(filename.empty() || toFind.empty() || toReplace.empty())
			return emptyArgs();
		
		std::ifstream infile(filename.c_str(), std::ifstream::in);
		if (!infile)
			return noInFile(filename);
		
		std::ofstream	outfile(filename.append(".replace").c_str(), std::ofstream::trunc);
		if (!outfile)
		{
			infile.close();
			return outFileErr(filename.append(".replace"));
		}

		replaceStrings(&infile, &outfile, toFind, toReplace);
		infile.close();
		outfile.close();
		return 0;
	}
	else
		return wrongArguments();
}
