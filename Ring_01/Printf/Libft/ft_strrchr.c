/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 12:34:41 by touteiro          #+#    #+#             */
/*   Updated: 2022/10/13 17:49:58 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	i;
	int				count;

	i = c;
	count = ft_strlen(s) - 1;
	if (i == '\0')
		return ((char *)(s + count + 1));
	while (count >= 0 && *(s + count))
	{
		if (*(s + count) == (char)i)
			return ((char *)(s + count));
		count--;
	}
	return (NULL);
}
