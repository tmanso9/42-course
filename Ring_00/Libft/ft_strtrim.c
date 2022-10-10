/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 00:18:56 by touteiro          #+#    #+#             */
/*   Updated: 2022/10/08 00:48:53 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
