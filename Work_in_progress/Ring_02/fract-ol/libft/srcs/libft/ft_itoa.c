/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:51:13 by touteiro          #+#    #+#             */
/*   Updated: 2022/11/29 19:28:24 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

static int	count_digits(int n)
{
	int	digits;

	digits = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		digits += 1;
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
char	*ft_itoa(int n)
{
	char			*str;
	int				digits;
	unsigned int	long_n;

	digits = count_digits(n);
	str = (char *)malloc(sizeof(char) * (digits + 1));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		long_n = n * -1;
	}
	else
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
