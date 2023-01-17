/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 19:06:54 by touteiro          #+#    #+#             */
/*   Updated: 2022/11/29 19:30:14 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

/*
The  memcmp()  function  compares the first n bytes (each
interpreted as unsigned char) of the memory areas s1 and s2.
The memcmp() function returns an integer less than, equal
to, or greater than zero if the first n bytes  of  s1  is
found,  respectively,  to  be  less than, to match, or be
greater than the first n bytes of s2.
For a nonzero return value, the sign is determined by the
sign  of  the  difference between the first pair of bytes
(interpreted as unsigned char) that differ in s1 and s2.
If n is zero, the return value is zero.
*/
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		i;
	const char	*str1;
	const char	*str2;

	i = 0;
	str1 = s1;
	str2 = s2;
	if (n == 0)
		return (0);
	while (i < n - 1 && str1[i] == str2[i])
		i++;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
