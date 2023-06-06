/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:24:22 by touteiro          #+#    #+#             */
/*   Updated: 2023/04/14 22:46:35 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "LinkedList.hpp"

class Character : public ICharacter
{
private:
	std::string	_name;
	AMateria	*inventory[4];
	LinkedList	dropped;
public:
	Character( void );
	Character( Character const & );
	~Character();
	Character & operator=( Character const & );
	
	Character( std::string );
	virtual std::string  const & getName() const;
	virtual void	equip(AMateria * m);
	virtual void	unequip(int idx);
	virtual void	use(int idx, ICharacter& target);
};


#endif