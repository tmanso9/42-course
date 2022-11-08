/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:56:59 by touteiro          #+#    #+#             */
/*   Updated: 2022/11/08 18:51:54 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hex_digits(unsigned int i)
{
	int	digits;

	digits = 0;
	if (i == 0)
		return (1);
	while (i > 0)
	{
		i /= 16;
		digits++;
	}
	return (digits);
}

void	ft_puthex(unsigned int i, char format)
{
	if (i < 16)
	{
		if (i < 10)
			ft_putchar_fd(i + '0', 1);
		else
		{
			if (format == 'x')
				ft_putchar_fd(i - 10 + 'a', 1);
			if (format == 'X')
				ft_putchar_fd(i - 10 + 'A', 1);
		}
	}
	if (i >= 16)
	{
		ft_puthex(i / 16, format);
		ft_puthex(i % 16, format);
	}
}

/*
%d or %i: The int (or appropriate variant) argument is converted to
signed decimal (d and i) notation.
*/
int	ft_print_x(t_print *tab, char format)
{
	unsigned int	i;

	i = va_arg(tab->args, unsigned int);
	if (i == 0)
	{
		ft_putchar_fd('0', 1);
		tab->printed += 1;
		return (1);
	}
	ft_puthex(i, format);
	tab->printed += hex_digits(i);
	return (1);
}
