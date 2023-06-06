/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:35:17 by touteiro          #+#    #+#             */
/*   Updated: 2023/05/25 15:30:53 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void)
{
	Data		*original = new Data;
	
	original->n = 65;
	original->c = 'r';
	std::cout << "Original Data *:\t\t" << original << std::endl;
	std::cout << "Original values:\t\t" << original->n << "\t" << original->c << std::endl;

	uintptr_t	serialized;
	Data		*finalRes;
	
	serialized = Serializer::serialize(original);
	std::cout << "\nUintptr after serializer:\t" << serialized << std::endl;
	
	finalRes = Serializer::deserialize(serialized);
	std::cout << "\nData * after deserializer:\t" << finalRes << std::endl;
	std::cout << "Values after deserializer:\t" << finalRes->n << "\t" << finalRes->c << std::endl;
	
	delete original;
}