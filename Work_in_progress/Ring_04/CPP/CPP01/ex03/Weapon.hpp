/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:45:49 by touteiro          #+#    #+#             */
/*   Updated: 2023/03/24 12:02:40 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon
{
private:
	std::string	_type;
public:
	Weapon(std::string type);
	~Weapon();
	
	std::string const & getType(void);
	void	setType(std::string type);
};





#endif