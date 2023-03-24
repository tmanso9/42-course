/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 12:47:52 by touteiro          #+#    #+#             */
/*   Updated: 2023/03/24 19:56:48 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int	outFileErr(std::string file);
int	noInFile(std::string file);
int	wrongArguments(void);

int main (int argc, char**argv)
{
	if (argc == 4)
	{
		std::string	filename = argv[1];
		std::ifstream infile(filename.c_str(), std::ifstream::in);
		if (!infile)
			return noInFile(filename);
		
		std::ofstream	outfile(filename.append(".replace").c_str(), std::ofstream::trunc);
		if (!outfile)
		{
			infile.close();
			return outFileErr(filename.append(".replace"));
		}
				
		std::string	str;
		std::string	toFind = argv[2];
		std::string	toReplace = argv[3];
		while (std::getline(infile, str))
		{
			if (!str.find(toFind.c_str()))
			{
				std::cout << "Found one!" << std::endl;
			}
			else
				outfile << str << std::endl;
		}
	}
	else
		return wrongArguments();
}
