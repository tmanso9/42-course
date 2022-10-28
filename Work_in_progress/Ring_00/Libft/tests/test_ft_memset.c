/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:27:22 by touteiro          #+#    #+#             */
/*   Updated: 2022/10/14 17:29:23 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_int_result(int n);

void	test_ft_memset(void)
{
	printf("TESTING ft_memset:\n\n");

	char	str[30] = "test";
	int		c = 'a';
	printf("INPUT: <test, a, 2>");
	printf("\nOriginal: 	%s", (char *)memset(str, c, 2));
	printf("\nMine:		%s", (char *)ft_memset(str, c, 2));

	printf("\nINPUT: <aast, a, 20>");
	printf("\nOriginal: 	%s", (char *)memset(str, c, 20));
	printf("\nMine:		%s", (char *)ft_memset(str, c, 20));

	c = '\n';
	printf("\nINPUT: <aaaaaaaaaaaaaaaaaaaa, \\n, 3>");
	printf("\nOriginal: 	%s", (char *)memset(str, c, 3));
	printf("\nMine:		%s", (char *)ft_memset(str, c, 3));

	c = '\0';
	printf("\nINPUT: <\\n\\n\\naaaaaaaaaaaaaaaaa, \\0, 20>");
	printf("\nOriginal: 	%s", (char *)memset(str, c, 20));
	printf("\nMine:		%s", (char *)ft_memset(str, c, 20));

	return ;
}
