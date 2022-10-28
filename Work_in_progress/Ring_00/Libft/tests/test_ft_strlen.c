/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:27:22 by touteiro          #+#    #+#             */
/*   Updated: 2022/10/14 16:44:24 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_int_result(int n);

void	test_ft_strlen(void)
{
	printf("TESTING ft_strlen:\n\n");

	printf("INPUT: <test 123>");
	printf("\nOriginal: 	%zu", strlen("test 123"));
	printf("\nMine:		%zu", ft_strlen("test 123"));

	printf("\nINPUT: <5\\06\\07\\08\\0>");
	printf("\nOriginal: 	%zu", strlen("5\06\07\08\0>"));
	printf("\nMine:		%zu", ft_strlen("5\06\07\08\0>"));

	printf("\nINPUT: <>");
	printf("\nOriginal: 	%zu", strlen(""));
	printf("\nMine:		%zu", ft_strlen(""));

	printf("\nINPUT: <	\\v\\r\\f\\t\\n>");
	printf("\nOriginal: 	%zu", strlen("	\v\r\f\t\n"));
	printf("\nMine:		%zu", ft_strlen("	\v\r\f\t\n"));
}
