/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:36:49 by touteiro          #+#    #+#             */
/*   Updated: 2022/11/29 19:26:52 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

static void	ft_width_dot_pt2(t_print *tab, char *str)
{
	if (tab->precision < (int)ft_strlen(str))
	{
		if (str[0] == '-')
			tab->precision = (int)ft_strlen(str) - 1;
		else
			if (!(tab->precision <= 0 && ft_atoi(str) == 0))
				tab->precision = (int)ft_strlen(str);
	}
	if (tab->plus && str[0] != '-')
	{
		ft_putchar_fd('+', 1);
		tab->printed += 1;
	}
	else if (tab->space && str[0] != '-')
	{
		ft_putchar_fd(' ', 1);
		tab->printed += 1;
		tab->width -= 1;
	}
}

static void	ft_width_dot(t_print *tab, char *str, int len, int i)
{
	ft_width_dot_pt2(tab, str);
	if ((!tab->precision || tab->precision == -1) && ft_atoi(str) == 0)
	{
		while (++i < (tab->width))
			ft_putchar_fd(' ', 1);
		tab->printed += tab->width;
		return ;
	}
	if (str[0] == '-')
		tab->precision += 1;
	while (++i < (tab->width - tab->precision))
		ft_putchar_fd(' ', 1);
	i = -1;
	if (str[0] == '-')
		ft_putchar_fd('-', 1);
	while (++i < (tab->precision - len))
		ft_putchar_fd('0', 1);
}

static void	ft_width_zero(t_print *tab, char *str, int len, int i)
{
	if (str[0] == '-')
		ft_putchar_fd('-', 1);
	if (tab->plus && str[0] != '-')
	{
		ft_putchar_fd('+', 1);
		tab->printed += 1;
	}
	else if (tab->space && str[0] != '-')
	{
		ft_putchar_fd(' ', 1);
		tab->printed += 1;
		tab->width -= 1;
	}
	while (++i < (tab->width - len))
		ft_putchar_fd('0', 1);
}

static void	width_initial_process(t_print *tab, char *str, int len, int i)
{
	if (tab->dot)
	{
		ft_width_dot(tab, str, len, i);
		return ;
	}
	if (tab->zero)
		ft_width_zero(tab, str, len, i);
	else
	{
		if (tab->plus && str[0] != '-')
		{
			ft_putchar_fd('+', 1);
			tab->printed += 1;
		}
		else if (tab->space && str[0] != '-')
		{
			ft_putchar_fd(' ', 1);
			tab->printed += 1;
			tab->width -= 1;
		}
		while (++i < (tab->width - len))
			ft_putchar_fd(' ', 1);
	}
}

void	ft_process_i_width(t_print *tab, char *str, int len, int i)
{
	width_initial_process(tab, str, len, i);
	if (tab->dot && tab->precision <= 0 && ft_atoi(str) == 0)
		return ;
	if (str[0] == '-' && (tab->zero || tab->dot))
		ft_putstr_fd(str + 1, 1);
	else
		ft_putstr_fd(str, 1);
	if (tab->width > len && tab->width > tab->precision)
		tab->printed += tab->width;
	else if (tab->dot && tab->precision > len)
		tab->printed += tab->precision;
	else
		tab->printed += len;
}
