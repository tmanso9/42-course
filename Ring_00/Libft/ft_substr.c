/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 20:52:56 by touteiro          #+#    #+#             */
/*   Updated: 2022/10/11 17:19:33 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (start > ft_strlen(s) - 1)
	{
		sub = malloc(1);
		ft_bzero(sub, 1);
		return (sub);
	}
	if (ft_strlen(s) <= len)
		sub = (char *)malloc(sizeof(char) * ((ft_strlen(s) - start) + 1));
	else
		sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, (char *)(s + start), len + 1);
	return (sub);
}
