/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 19:38:47 by touteiro          #+#    #+#             */
/*   Updated: 2022/11/29 19:27:54 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

/*
The bzero() function writes n zeroed bytes to the string s.  If n is zero,
bzero() does nothing.
*/
void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	if (n == 0)
		return ;
	str = s;
	i = 0;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}
