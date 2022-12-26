/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 18:52:24 by touteiro          #+#    #+#             */
/*   Updated: 2022/12/24 01:30:36 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

int	ft_strlen_gnl(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n' )
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

char	*strjoin_gnl(char *s1, char *s2)
{
	int		size_concat;
	char	*concat;
	int		i;
	int		j;

	i = 0;
	j = -1;
	size_concat = ft_strlen_gnl(s1) + ft_strlen_gnl(s2);
	concat = (char *)malloc(size_concat + 1 * sizeof(char));
	if (!concat)
		return (NULL);
	while (s1 && s1[i])
	{
		concat[i] = s1[i];
		i++;
	}
	while (s2[++j])
	{
		concat[i++] = s2[j];
		if (s2[j] == '\n')
			break ;
	}
	concat[i] = 0;
	free(s1);
	return (concat);
}
