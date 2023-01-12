/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:51:16 by touteiro          #+#    #+#             */
/*   Updated: 2022/11/29 19:30:11 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

/*
The memchr() function scans the initial n  bytes  of  the
memory  area pointed to by s for the first instance of c.
Both c and the bytes of the memory area pointed to  by  s
are interpreted as unsigned char.
The memchr() function returns a pointer  to
the matching byte or NULL if the character does not occur
in the given memory area.
*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	const char		*str;

	i = 0;
	str = (char *)s;
	if (n == 0)
		return (NULL);
	while (i < n)
	{
		if ((unsigned char)str[i] == (unsigned char)c)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}
