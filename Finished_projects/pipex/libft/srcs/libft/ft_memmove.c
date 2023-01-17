/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:11:48 by touteiro          #+#    #+#             */
/*   Updated: 2022/11/29 19:30:20 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

static void	dst_bigger(char *d, char *s, size_t len)
{
	size_t	i;

	i = len;
	while (i > 0)
	{
		i--;
		d[i] = s[i];
	}
}

/*
In the case of this function, unlike memcpy, the strs can overlap.
This means that we have to check is dst > src, and if it is, we copy from end
of len bytes to beginning of dst (i = len, starting at i--) to dst.
If they don't overlap, we do simple memcpy.
*/
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;

	d = (char *)dst;
	s = (char *)src;
	if (!d && !s)
		return (dst);
	if (dst > src)
		dst_bigger(d, s, len);
	else
		dst = ft_memcpy(d, s, len);
	return (dst);
}
