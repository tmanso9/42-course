/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 18:29:44 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/04 18:45:32 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{
private:
	/* data */
public:
	FragTrap();
	FragTrap( std::string );
	FragTrap( FragTrap const &);
	~FragTrap();

	FragTrap & operator=( FragTrap const & );
	void	highFivesGuys();
    int     getDamage() const;
    int     getHitPoints() const;
};




#endif