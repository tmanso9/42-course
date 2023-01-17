/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:56:59 by touteiro          #+#    #+#             */
/*   Updated: 2022/11/29 19:27:22 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

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

static void	ft_process_cardinal(t_print *tab, char format)
{
	if (format == 'x')
		ft_putstr_fd("0x", 1);
	else
		ft_putstr_fd("0X", 1);
	tab->printed += 2;
}

static void	ft_process_x_flags(t_print *tab, unsigned int i, char format, \
	int count)
{
	if (tab->dash)
		ft_process_x_dash(tab, i, format, count);
	else if (tab->zero || tab->width)
		ft_process_x_width(tab, i, format, count);
	else
		ft_process_x_dot(tab, i, format, count);
}

/*
%d or %i: The int (or appropriate variant) argument is converted to
signed decimal (d and i) notation.
*/
int	ft_print_x(t_print *tab, char format)
{
	unsigned int	i;
	int				count;

	i = va_arg(tab->args, unsigned int);
	count = -1;
	if (i == 0 && !tab->dot && !tab->width)
	{
		ft_putchar_fd('0', 1);
		tab->printed += 1;
		return (1);
	}
	if (tab->cardinal && !tab->width && !tab->zero)
		ft_process_cardinal(tab, format);
	if (tab->dot || tab->dash || tab->zero || tab->width)
		ft_process_x_flags(tab, i, format, count);
	else
	{
		ft_puthex(i, format);
		tab->printed += hex_digits(i);
	}
	return (1);
}
