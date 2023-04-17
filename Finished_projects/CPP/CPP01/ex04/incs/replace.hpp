/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 22:29:09 by touteiro          #+#    #+#             */
/*   Updated: 2023/03/24 22:35:31 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
# define REPLACE_HPP

#include <iostream>
#include <fstream>

int		outFileErr(std::string file);
int		noInFile(std::string file);
int		wrongArguments(void);
int		emptyArgs(void);
void	replaceStrings(std::ifstream *infile, std::ofstream *outfile, std::string toFind, std::string toReplace);

#endif
