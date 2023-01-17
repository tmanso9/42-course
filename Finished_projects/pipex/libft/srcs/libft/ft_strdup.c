/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 20:35:45 by touteiro          #+#    #+#             */
/*   Updated: 2022/11/29 19:30:45 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

/*
The strdup() function returns a pointer to a new string which is  a
duplicate  of  the string s.  Memory for the new string is obtained
with malloc(3), and can be freed with free(3).
*/
char	*ft_strdup(const char *s1)
{
	char	*s2;

	s2 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!s2)
		return (NULL);
	ft_strlcpy(s2, (char *)s1, ft_strlen(s1) + 1);
	return (s2);
}
