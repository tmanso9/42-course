/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 12:25:50 by touteiro          #+#    #+#             */
/*   Updated: 2023/03/24 12:34:24 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB
{
private:
	std::string	_name;
	Weapon	*_weapon;

public:
	HumanB(std::string name);
	~HumanB();

	void	setWeapon(Weapon &weapon);
	void	attack(void);
};




#endif