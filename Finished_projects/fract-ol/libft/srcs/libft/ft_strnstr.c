/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 19:15:08 by touteiro          #+#    #+#             */
/*   Updated: 2022/11/29 19:31:20 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

/*
The strnstr() function locates the first occurrence of the 
null-terminated string needle in the string haystack, where not
more than len characters are searched.  Characters that ap‐
pear after a ‘\0’ character are not searched.
If needle is an empty string, haystack is returned; if needle
occurs nowhere in haystack, NULL is returned; otherwise a
pointer to the first character of the first occurrence of
needle is returned.
*/
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (ft_strlen(needle) == 0 || (!needle && len == 0))
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	while (haystack[i])
	{
		while (haystack[i + count] == needle[count]
			&& haystack[i + count]
			&& i + count < len)
			count++;
		if (count == ft_strlen(needle))
			return ((char *)(haystack + i));
		i++;
		count = 0;
	}
	return (NULL);
}
