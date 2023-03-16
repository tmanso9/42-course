/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:17:58 by touteiro          #+#    #+#             */
/*   Updated: 2023/02/15 15:29:30 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Testing the original function, we verify that it segfaults when given a NULL
string as parameter. For this reason, in our version of the function we don't
check to see if the input is null before running the rest of the code.
*/
size_t	ft_strlen(const char *str)
{
	int	size;

	size = 0;
	if (!str)
		return (0);
	while (str[size])
		size++;
	return (size);
}
