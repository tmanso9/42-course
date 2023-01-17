/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 00:09:35 by touteiro          #+#    #+#             */
/*   Updated: 2022/11/29 19:31:02 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

/*
Allocates (with malloc(3)) and returns a new string,
which is the result of the concatenation of ’s1’ and ’s2’.
Returns the new string.  NULL if the allocation fails.
*/
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
