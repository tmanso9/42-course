/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 12:34:41 by touteiro          #+#    #+#             */
/*   Updated: 2022/11/29 19:30:42 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

/*
The  strchr() function returns a pointer to the first occurrence
of the character c in the string s.
The int that is to be found is converted to unsigned int in case it is 
bigger than 128 (outside of ascii table).
*/
char	*ft_strchr(const char *s, int c)
{
	unsigned char	i;

	i = c;
	while (*s)
	{
		if (*s == (char)i)
			return ((char *)s);
		s++;
	}
	if (i == '\0')
		return ((char *)s);
	return (NULL);
}
