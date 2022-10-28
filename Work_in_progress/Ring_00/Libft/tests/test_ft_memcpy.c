/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:27:50 by touteiro          #+#    #+#             */
/*   Updated: 2022/10/17 14:40:34 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	test_ft_memcpy(void)
{
	printf("TESTING ft_memcpy:\n\n");

	char	str[10] = "test";
	char	str1[10] = "";
	char	str2[10] = "";
	printf("INPUT: <dst, 'test', 2>");
	printf("\nOriginal: 	%s", (char *)memcpy(str1, str, 2));
	printf("\nMine:		%s", (char *)ft_memcpy(str2, str, 2));

	char	str3[30] = "";
	char	str4[30] = "";
	printf("\nINPUT: <dst, 'ahdvujyegbdjgvhqed', 0>");
	printf("\nOriginal: 	%s", (char *)memcpy(str3, "ahdvujyegbdjgvhqed", 0));
	printf("\nMine:		%s", (char *)ft_memcpy(str4, "ahdvujyegbdjgvhqed", 0));
	
	printf("\nINPUT: <dst, 'ahdvujyegbdjgvhqed', 15>");
	printf("\nOriginal: 	%s", (char *)memcpy(str3, "ahdvujyegbdjgvhqed", 15));
	printf("\nMine:		%s", (char *)ft_memcpy(str4, "ahdvujyegbdjgvhqed", 15));
}
