/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:47:45 by touteiro          #+#    #+#             */
/*   Updated: 2023/06/06 17:03:27 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <sstream>
# include <cstdlib>
# include <stack>

class RPN
{
	private:
		RPN( void );
		RPN( RPN const & );
		RPN & operator=( RPN const & );
		
		static std::stack<float>	_operands;
		static std::string			_tokens;
		static float (*ops[4])( float, float );

		static void		doOp( std::string );
		static float	add( float, float );
		static float	subtract( float, float );
		static float	multiply( float, float );
		static float	divide( float, float );

		static void	checkErrs( std::string );
		static void	errOut( std::string );
		
	public:
		~RPN();
		
		static void calc( std::string );
};

#endif // !RPN_HPP