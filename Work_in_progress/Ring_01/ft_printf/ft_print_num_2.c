/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:36:49 by touteiro          #+#    #+#             */
/*   Updated: 2022/11/04 18:44:50 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_process_i_dash(t_print *tab, char *str, int len, int i)
{
	if (tab->dot)
	{
		while (++i < (tab->precision - len))
			ft_putchar_fd('0', 1);
		i = -1;
	}
	ft_putstr_fd(str, 1);
	if (tab->width > len)
	{
		if (tab->precision > len)
			while (++i < (tab->width - tab->precision))
				ft_putchar_fd(' ', 1);
		else
			while (++i < (tab->width - len))
				ft_putchar_fd(' ', 1);
		tab->printed += tab->width;
	}
	else
		tab->printed += len;
}

static void	width_initial_process(t_print *tab, char *str, int len, int i)
{
	if (tab->dot)
	{
		while (++i < (tab->width - tab->precision))
			ft_putchar_fd(' ', 1);
		i = -1;
		while (++i < (tab->precision - len))
			ft_putchar_fd('0', 1);
		i = -1;
		return ;
	}
	if (tab->zero)
	{
		if (str[0] == '-')
			ft_putchar_fd('-', 1);
		if (tab->precision > len)
			while (++i < (tab->width - tab->precision))
				ft_putchar_fd('0', 1);
		else
			while (++i < (tab->width - len))
				ft_putchar_fd('0', 1);
	}
	else
		while (++i < (tab->width - tab->precision))
			ft_putchar_fd(' ', 1);
}

void	ft_process_i_width(t_print *tab, char *str, int len, int i)
{
	width_initial_process(tab, str, len, i);
	if (str[0] == '-' && tab->zero)
		ft_putstr_fd(str + 1, 1);
	else
		ft_putstr_fd(str, 1);
	if (tab->width > len)
		tab->printed += tab->width;
	else
		tab->printed += len;
}

void	ft_process_i_dot(t_print *tab, char *str, int len, int i)
{
	if (str[0] == '-')
	{
		ft_putchar_fd('-', 1);
		tab->precision++;
	}
	while (++i < (tab->precision - len))
		ft_putchar_fd('0', 1);
	if (str[0] == '-')
		ft_putstr_fd(str + 1, 1);
	else
		ft_putstr_fd(str, 1);
	if (tab->precision > len)
		tab->printed += tab->precision;
	else
		tab->printed += len;
}
