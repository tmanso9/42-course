/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:21:56 by touteiro          #+#    #+#             */
/*   Updated: 2022/11/29 19:27:12 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

static void	ft_process_width_dot_pt2(t_print *tab, int i, int len, char format)
{
	while (++i < (tab->width - tab->precision))
		ft_putchar_fd(' ', 1);
	i = -1;
	if (tab->cardinal && tab->width)
	{
		if (format == 'x')
			ft_putstr_fd("0x", 1);
		else
			ft_putstr_fd("0X", 1);
		tab->printed += 2;
		tab->width -= 2;
	}
	while (++i < (tab->precision - len))
		ft_putchar_fd('0', 1);
}

static void	ft_process_width_dot(t_print *tab, unsigned int num, char format, \
	int i)
{
	int	len;

	len = hex_digits(num);
	if (tab->precision < len && !(tab->precision <= 0 && num == 0))
		tab->precision = len;
	if ((!tab->precision || tab->precision == -1) && num == 0)
	{
		while (++i < (tab->width))
			ft_putchar_fd(' ', 1);
		tab->printed += tab->width;
		return ;
	}
	ft_process_width_dot_pt2(tab, i, len, format);
}

static void	ft_process_width_zero(t_print *tab, int len, char format, int i)
{
	while (++i < (tab->width - len))
		ft_putchar_fd('0', 1);
	if (tab->cardinal)
	{
		if (format == 'x')
			ft_putstr_fd("0x", 1);
		else
			ft_putstr_fd("0X", 1);
		tab->printed += 2;
		tab->width -= 2;
	}
}

static void	width_initial_process(t_print *tab, unsigned int num, \
	char format, int i)
{
	int	len;

	len = hex_digits(num);
	if (tab->dot)
	{
		ft_process_width_dot(tab, num, format, i);
		return ;
	}
	if (tab->zero)
		ft_process_width_zero(tab, len, format, i);
	else
	{
		while (++i < (tab->width - len))
			ft_putchar_fd(' ', 1);
		if (tab->cardinal)
		{
			if (format == 'x')
				ft_putstr_fd("0x", 1);
			else
				ft_putstr_fd("0X", 1);
			tab->printed += 2;
			tab->width -= 2;
		}
	}
}

void	ft_process_x_width(t_print *tab, unsigned int num, char format, int i)
{
	int	len;

	len = hex_digits(num);
	width_initial_process(tab, num, format, i);
	if (!(tab->precision <= 0 && num == 0 && tab->dot))
	{
		ft_puthex(num, format);
		if (tab->width > len && tab->width > tab->precision)
			tab->printed += tab->width;
		else if (tab->dot && tab->precision > len)
			tab->printed += tab->precision;
		else
			tab->printed += len;
	}
}
