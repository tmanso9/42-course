/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 00:18:56 by touteiro          #+#    #+#             */
/*   Updated: 2022/11/29 19:31:26 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

/*
Allocates (with malloc(3)) and returns a copy of
’s1’ with the characters specified in ’set’ removed
from the beginning and the end of the string.
Returns the trimmed string.  NULL if the allocation fails.
We do it by counting how many chars we have to skip in the beginning (i)
and how many we have to skip in the end (end), and copying the rest.
*/
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		end;

	i = 0;
	end = ft_strlen(s1);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (s1[end - 1] && ft_strchr(set, s1[end - 1]) && end > i)
		end--;
	str = (char *)malloc(sizeof(char) * (end - i + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, (char *)(s1 + i), (end - i + 1));
	return (str);
}
