/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:56:59 by touteiro          #+#    #+#             */
/*   Updated: 2022/10/20 12:24:01 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_digits(unsigned int n)
{
	int	digits;

	digits = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		count_digits(n = n / 10);
		digits++;
	}
	return (digits);
}

/*
Allocates (with malloc(3)) and returns a string
representing the integer received as an argument.
Negative numbers must be handled.
*/
static char	*ft_uitoa(unsigned int n)
{
	char				*str;
	int					digits;
	unsigned long int	long_n;

	digits = count_digits(n);
	str = (char *)malloc(sizeof(char) * (digits + 1));
	if (!str)
		return (NULL);
	long_n = n;
	if (long_n == 0)
		str[0] = '0';
	str[digits] = '\0';
	while (long_n != 0)
	{
		str[digits - 1] = (long_n % 10) + '0';
		long_n = long_n / 10;
		digits--;
	}
	return (str);
}

/*
%d or %i: The int (or appropriate variant) argument is converted to
signed decimal (d and i) notation.
*/
int	ft_print_i(int i)
{
	char	*str;
	int		len;

	str = ft_itoa(i);
	len = ft_strlen(str);
	if (!len)
		return (0);
	ft_putstr_fd(str, 1);
	free (str);
	return (len);
}

int	ft_print_u(unsigned int i)
{
	char	*str;
	int		len;

	str = ft_uitoa(i);
	len = ft_strlen(str);
	if (!len)
		return (0);
	ft_putstr_fd(str, 1);
	free (str);
	return (len);
}
