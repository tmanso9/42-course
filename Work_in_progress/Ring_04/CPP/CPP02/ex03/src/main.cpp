/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:32:46 by touteiro          #+#    #+#             */
/*   Updated: 2023/03/31 15:42:11 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int	main ( void )
{
	Point	a;
	Point	b(-4.0f, 3.5f);
	Point	c ( b );

	std::cout << c.getXValue() << std::endl;
}