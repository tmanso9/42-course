/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 18:29:44 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/14 14:02:15 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{
public:
	FragTrap();
	FragTrap( std::string );
	FragTrap( FragTrap const &);
	~FragTrap();

	FragTrap & operator=( FragTrap const & );
	void	highFivesGuys();
};

#endif