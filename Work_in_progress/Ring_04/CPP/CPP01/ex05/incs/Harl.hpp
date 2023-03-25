/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 13:06:38 by touteiro          #+#    #+#             */
/*   Updated: 2023/03/25 16:25:12 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <cstdlib>

class Harl
{
private:
	void		_debug(void);
	void		_info(void);
	void		_warning(void);
	void		_error(void);
	std::string	_levels[4];
	
public:
	Harl(void);
	~Harl();
	void	complain(std::string level);
};




#endif