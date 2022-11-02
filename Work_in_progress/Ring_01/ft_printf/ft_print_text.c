/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_text.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:56:59 by touteiro          #+#    #+#             */
/*   Updated: 2022/10/28 17:12:57 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
%c: The int argument is converted to an unsigned char,
and the resulting character is written.
*/
int	ft_print_c(int c)
{
	unsigned char	un_c;

	un_c = (unsigned char)c;
	return (write(1, &un_c, 1));
}

/*
%s: The char * argument is expected to be a pointer to an array of
character type (pointer to a string).  Characters from the array
are written up to (but not including) a terminating NUL character.
*/
int	ft_print_s(char *str)
{
	size_t	len;

	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (!len)
		return (0);
	ft_putstr_fd(str, 1);
	return (len);
}
