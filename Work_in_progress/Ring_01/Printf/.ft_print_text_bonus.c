/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_text_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:56:59 by touteiro          #+#    #+#             */
/*   Updated: 2022/10/20 19:19:41 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

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
int	ft_print_s(char *str, const char *arg, int *i, int advance)
{
	size_t	len;
	int		j = 0;
	len = 0;
	if (advance > 0)
	{
		if (arg[*i - advance] == '.')
		{
			if (arg[*i - advance + 1] >= '0' && arg[*i - advance + 1] >= '0')
			{
				if (!str)
					str = "(null)";
				len = ft_strlen(str) + 2;
				if (!len)
					return (0);
				while (str[j] && j < (arg[*i - advance + 1] - '0'))
				{
					write(1, &str[j], 1);
					j++;
				}
			}
		}
	}
	else
	{
		if (!str)
			str = "(null)";
		len = ft_strlen(str);
		if (!len)
			return (0);
		ft_putstr_fd(str, 1);
	}
	return (len);
}
