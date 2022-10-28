/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_bzero.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:27:22 by touteiro          #+#    #+#             */
/*   Updated: 2022/10/14 17:29:23 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_int_result(int n);

void	test_ft_bzero(void)
{
	printf("TESTING ft_bzero:\n\n");

	char	str[10] = "test";
	char	str1[10] = "test";
	printf("INPUT: <test, 3>");
	bzero(str, 2);
	printf("\nOriginal: 	%s", str);
	ft_bzero(str1, 2);
	printf("\nMine:		%s", str1);

	char	str3[10] = "test";
	char	str4[10] = "test";
	printf("\nINPUT: <test, 0>");
	bzero(str3, (0));
	printf("\nOriginal: 	%s", str3);
	ft_bzero(str4, 0);
	printf("\nMine:		%s", str4);

}
