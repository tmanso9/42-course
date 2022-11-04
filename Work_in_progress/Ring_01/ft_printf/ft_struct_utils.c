/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:02:36 by touteiro          #+#    #+#             */
/*   Updated: 2022/11/04 18:55:43 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_print	*initialize_struct(t_print *tab)
{
	tab->width = 0;
	tab->precision = 0;
	tab->dot = 0;
	tab->dash = 0;
	tab->zero = 0;
	tab->cardinal = 0;
	return (tab);
}

static int	process_width(t_print *tab, const char *str, int i)
{
	int	count;

	count = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		count++;
		i += 1;
	}
	while (count > 0)
	{
		tab->width *= 10;
		tab->width += (str[i - count] - '0');
		count--;
	}
	return (i);
}

static int	process_precision(t_print *tab, const char *str, int i)
{
	int	count;

	count = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		count++;
		i += 1;
	}
	while (count > 0)
	{
		tab->precision *= 10;
		tab->precision += (str[i - count] - '0');
		count--;
	}
	return (i);
}

int	initial_str_loop(t_print *tab, const char *str, int i)
{
	while (str[i] != '%' && str[i] != 'c' && str[i] != 's' && str[i] != 'i' && \
		str[i] != 'd' && str[i] != 'p' && str[i] != 'u' && str[i] != 'x' && \
		str[i] != 'X')
	{
		if (str[i] == '-')
		{
			tab->dash = 1;
			i++;
		}
		if (str[i] == '0')
		{
			tab->zero = 1;
			i++;
		}
		if (str[i] == '.')
		{
			tab->dot = 1;
			i++;
			i = process_precision(tab, str, i);
		}
		if (str[i] == '#')
		{
			tab->cardinal = 1;
			i++;
		}
		i = process_width(tab, str, i);
	}
	return (i);
}
