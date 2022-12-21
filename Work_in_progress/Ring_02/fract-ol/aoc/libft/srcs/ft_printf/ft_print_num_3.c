/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:27:42 by touteiro          #+#    #+#             */
/*   Updated: 2022/11/29 19:26:57 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

static void	ft_process_i_dash_pt2(t_print *tab, char *str, int len, int i)
{
	if (tab->space && str[0] != '-')
	{
		ft_putchar_fd(' ', 1);
		tab->printed += 1;
		tab->width -= 1;
	}
	if (str[0] == '-' && tab->dot)
		ft_putstr_fd(str + 1, 1);
	else
		ft_putstr_fd(str, 1);
	if (tab->width > len)
	{
		if (tab->precision > len)
			while (++i < (tab->width - tab->precision))
				ft_putchar_fd(' ', 1);
		else
			while (++i < (tab->width - len))
				ft_putchar_fd(' ', 1);
		tab->printed += (return_biggest(tab->precision, tab->width));
	}
	else
		tab->printed += (return_biggest(tab->precision, len));
}

void	ft_process_i_dash(t_print *tab, char *str, int len, int i)
{
	if (tab->dot)
	{
		if ((!tab->precision || tab->precision == -1) && ft_atoi(str) == 0)
		{
			while (++i < (tab->width))
				ft_putchar_fd(' ', 1);
			tab->printed += tab->width;
			return ;
		}
		if (str[0] == '-')
		{
			ft_putchar_fd('-', 1);
			tab->precision += 1;
		}
		while (++i < (tab->precision - len))
			ft_putchar_fd('0', 1);
		i = -1;
	}
	ft_process_i_dash_pt2(tab, str, len, i);
}

static void	ft_process_i_dot_pt2(t_print *tab, char *str)
{
	if (str[0] == '-')
	{
		ft_putchar_fd('-', 1);
		tab->precision++;
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
	}
}

void	ft_process_i_dot(t_print *tab, char *str, int len, int i)
{
	ft_process_i_dot_pt2(tab, str);
	if (tab->precision <= 0 && ft_atoi(str) == 0)
		return ;
	while (++i < (tab->precision - len))
		ft_putchar_fd('0', 1);
	if (str[0] == '-')
		ft_putstr_fd(str + 1, 1);
	else
		ft_putstr_fd(str, 1);
	tab->printed += return_biggest(tab->precision, len);
}
