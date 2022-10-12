/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 19:15:08 by touteiro          #+#    #+#             */
/*   Updated: 2022/10/11 16:58:34 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
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
