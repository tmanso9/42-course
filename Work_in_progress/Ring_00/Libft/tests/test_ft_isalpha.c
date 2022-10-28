/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isalpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:27:22 by touteiro          #+#    #+#             */
/*   Updated: 2022/10/14 16:12:37 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_int_result(int n);

void	test_ft_isalpha(void)
{
	write(1, "TESTING ft_isalpha:\n\n", 21);
	write(1, "INPUT: 3\n", 9);
	write(1, "Original: 	", 11);
	ft_print_int_result(isalpha('3'));
	write(1, "\nMine:		", 8);
	ft_print_int_result(ft_isalpha('3'));
	write(1, "\nINPUT: a\n", 10);
	write(1, "Original: 	", 11);
	ft_print_int_result(isalpha('a'));
	write(1, "\nMine:		", 8);
	ft_print_int_result(ft_isalpha('a'));
	write(1, "\nINPUT: A\n", 10);
	write(1, "Original: 	", 11);
	ft_print_int_result(isalpha('A'));
	write(1, "\nMine:		", 8);
	ft_print_int_result(ft_isalpha('A'));
	write(1, "\nINPUT: space\n", 14);
	write(1, "Original: 	", 11);
	ft_print_int_result(isalpha(32));
	write(1, "\nMine:		", 8);
	ft_print_int_result(ft_isalpha(32));
	write(1, "\nINPUT: nul\n", 12);
	write(1, "Original: 	", 11);
	ft_print_int_result(isalpha(0));
	write(1, "\nMine:		", 8);
	ft_print_int_result(ft_isalpha(0));
}
