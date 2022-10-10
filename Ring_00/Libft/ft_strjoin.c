/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 00:09:35 by touteiro          #+#    #+#             */
/*   Updated: 2022/10/08 00:15:30 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;

	join = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!join)
		return (NULL);
	ft_strlcpy(join, (char *)s1, ft_strlen(s1) + 1);
	ft_strlcpy(join + ft_strlen(s1), (char *)s2, ft_strlen(s2) + 1);
	return (join);
}
