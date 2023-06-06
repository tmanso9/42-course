/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:46:27 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/10 19:25:03 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
private:
	Weapon &_weapon;
	std::string	_name;

public:
	HumanA(std::string name, Weapon &weapon);
	~HumanA();

	void	attack(void);
};


#endif