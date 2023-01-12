/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 20:52:56 by touteiro          #+#    #+#             */
/*   Updated: 2022/11/29 19:31:29 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

/*
Allocates and returns a substring from the string ’s’.
The substring begins at index ’start’ and is of maximum size ’len’.
Returns the substring.  NULL if the allocation fails.
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	malloc_size;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s) || ft_strlen(s) == 0 || (int)start < 0 || len == 0)
	{
		sub = malloc(1);
		ft_bzero(sub, 1);
		return (sub);
	}
	if (ft_strlen(s) <= len)
	{
		sub = (char *)malloc(sizeof(char) * ((ft_strlen(s) - start) + 1));
		malloc_size = (ft_strlen(s) - start) + 1;
	}
	else
	{
		sub = (char *)malloc(sizeof(char) * (len + 1));
		malloc_size = len + 1;
	}
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, (char *)(s + start), malloc_size);
	return (sub);
}
