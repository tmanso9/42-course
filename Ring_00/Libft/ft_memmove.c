/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:11:48 by touteiro          #+#    #+#             */
/*   Updated: 2022/10/13 16:26:20 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void static	dst_bigger(size_t i, char *d, char *s, size_t len)
{
	i = len;
	while (i > 0)
	{
		i--;
		d[i] = s[i];
	}
}

void static	src_bigger(size_t i, char *d, char *s, size_t len)
{
	while (i < len)
	{
		d[i] = s[i];
		i++;
	}
}

/* In the case of this function, unlike memcpy, the strs can overlap.
This means that we have to check is dst > src, and if it is, we copy from end
of len bytes to beginning of dst (i = len, starting at i--) to dst.
If they don't overlap, we do simple memcpy.
*/
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*d;
	char	*s;

	i = 0;
	d = (char *)dst;
	s = (char *)src;
	if (!d && !s)
		return (dst);
	if (dst > src)
		dst_bigger(i, d, s, len);
	else
		src_bigger(i, d, s, len);
	return (dst);
}
