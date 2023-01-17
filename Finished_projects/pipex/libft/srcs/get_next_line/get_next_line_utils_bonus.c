/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 18:52:24 by touteiro          #+#    #+#             */
/*   Updated: 2022/11/29 19:46:02 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*join;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (s2 && !s1)
	{
		s1 = (char *)malloc(1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	join = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!join)
		return (NULL);
	while (s1[++i])
		join[i] = s1[i];
	while (s2[j])
		join[i++] = s2[j++];
	join[i] = '\0';
	free (s1);
	return (join);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	unsigned char	i;

	i = c;
	if (!s)
		return (NULL);
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
