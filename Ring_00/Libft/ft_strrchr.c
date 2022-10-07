/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 12:34:41 by touteiro          #+#    #+#             */
/*   Updated: 2022/10/07 13:10:01 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	int				count;

	i = c;
	count = ft_strlen(s) - 1;
	if (i == '\0')
		return ((char *)(s + count + 1));
	while (*(s + count))
	{
		if (*(s + count) == (char)i)
			return ((char *)(s + count));
		count--;
	}
	return (NULL);
}
