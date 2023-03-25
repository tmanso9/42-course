/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 19:22:27 by touteiro          #+#    #+#             */
/*   Updated: 2023/03/22 19:22:31 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

std::string	removeSpaces(std::string str)
{
	while (std::isspace(*str.begin()))
		str.erase(0, 1);
	while (std::isspace(*str.end()))
		str.erase(str.size() - 1, 1);
	return (str);
}
