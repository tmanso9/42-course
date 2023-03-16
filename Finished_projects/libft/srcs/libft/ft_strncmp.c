/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:17:38 by touteiro          #+#    #+#             */
/*   Updated: 2023/02/14 19:52:16 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The strncmp() function compares only the first (at most) n bytes of s1 and s2.
The  strcmp()  and  strncmp() functions return an integer
less than, equal to, or greater than zero if s1 (or  the
first n bytes thereof) is found, respectively, to be less
than, to match, or be greater than s2.
*/
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && s1 && s1[i] && s2 && s2[i] && s1[i] == s2[i])
		i++;
	if (!s1)
		return (-(unsigned char)s2[i]);
	if (!s2)
		return ((unsigned char)s1[i]);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
