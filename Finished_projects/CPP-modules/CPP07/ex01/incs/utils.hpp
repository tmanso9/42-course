/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 17:36:47 by touteiro          #+#    #+#             */
/*   Updated: 2023/05/26 17:37:05 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>

template<typename T>
void	printVal( T & data ){
	std::cout << data << "\t";
}

template<typename T>
void	timesTwo( T & data ){
	data *= 2;
}