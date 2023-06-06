/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 19:22:40 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/06 16:58:42 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef UTILS_HPP
# define UTILS_HPP

# include <string>
# include <iostream>

# define LOG(x) std::cout << x << std::endl

std::string	removeSpaces(std::string str);

#endif
