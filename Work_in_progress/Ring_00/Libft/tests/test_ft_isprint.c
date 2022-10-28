/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isprint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:27:22 by touteiro          #+#    #+#             */
/*   Updated: 2022/10/14 16:17:45 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_int_result(int n);

void	test_ft_isprint(void)
{
	write(1, "TESTING ft_isprint:\n\n", 21);
	write(1, "INPUT: 3\n", 9);
	write(1, "Original: 	", 11);
	ft_print_int_result(isprint('3'));
	write(1, "\nMine:		", 8);
	ft_print_int_result(ft_isprint('3'));
	write(1, "\nINPUT: a\n", 10);
	write(1, "Original: 	", 11);
	ft_print_int_result(isprint('a'));
	write(1, "\nMine:		", 8);
	ft_print_int_result(ft_isprint('a'));
	write(1, "\nINPUT: (int)320\n", 17);
	write(1, "Original: 	", 11);
	ft_print_int_result(isprint(320));
	write(1, "\nMine:		", 8);
	ft_print_int_result(ft_isprint(320));
	write(1, "\nINPUT: space\n", 14);
	write(1, "Original: 	", 11);
	ft_print_int_result(isprint(32));
	write(1, "\nMine:		", 8);
	ft_print_int_result(ft_isprint(32));
	write(1, "\nINPUT: nul\n", 12);
	write(1, "Original: 	", 11);
	ft_print_int_result(isprint(0));
	write(1, "\nMine:		", 8);
	ft_print_int_result(ft_isprint(0));
}
