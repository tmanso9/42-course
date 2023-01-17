/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:46:33 by touteiro          #+#    #+#             */
/*   Updated: 2022/11/29 19:27:16 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

static void	ft_process_after_print(t_print *tab, int len, int i)
{
	if (tab->width > len)
	{
		if (tab->precision > len)
			while (++i < (tab->width - tab->precision))
				ft_putchar_fd(' ', 1);
		else
			while (++i < (tab->width - len))
				ft_putchar_fd(' ', 1);
		if (tab->precision > tab->width)
			tab->printed += tab->precision;
		else
			tab->printed += tab->width;
	}
	else
	{
		if (tab->dot && tab->precision > len)
			tab->printed += tab->precision;
		else
			tab->printed += len;
	}
}

void	ft_process_x_dash(t_print *tab, unsigned int num, char format, int i)
{
	int	len;

	len = hex_digits(num);
	if (tab->dot)
	{
		if ((!tab->precision || tab->precision == -1) && num == 0)
		{
			while (++i < (tab->width))
				ft_putchar_fd(' ', 1);
			tab->printed += tab->width;
			return ;
		}
		while (++i < (tab->precision - len))
			ft_putchar_fd('0', 1);
		i = -1;
	}
	ft_puthex(num, format);
	ft_process_after_print(tab, len, i);
}

void	ft_process_x_dot(t_print *tab, unsigned int num, char format, int i)
{
	int	len;

	len = hex_digits(num);
	if (tab->precision <= 0 && num == 0)
		return ;
	if (tab->precision < 0)
		tab->precision = 0;
	while (++i < (tab->precision - len))
		ft_putchar_fd('0', 1);
	ft_puthex(num, format);
	if (tab->precision > len)
		tab->printed += tab->precision;
	else
		tab->printed += len;
}
