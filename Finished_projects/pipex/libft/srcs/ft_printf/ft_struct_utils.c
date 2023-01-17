/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:02:36 by touteiro          #+#    #+#             */
/*   Updated: 2022/11/29 19:27:33 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

t_print	*initialize_struct(t_print *tab)
{
	tab->width = 0;
	tab->precision = 0;
	tab->dot = 0;
	tab->dash = 0;
	tab->zero = 0;
	tab->cardinal = 0;
	tab->space = 0;
	tab->plus = 0;
	return (tab);
}

static int	process_width(t_print *tab, const char *str, int i)
{
	int	count;

	count = 0;
	while (ft_isdigit(str[i]))
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
	if (str[i] == '0' && !ft_isdigit(str[i + 1]))
	{
		tab->precision = -1;
		return (i + 1);
	}
	while (ft_isdigit(str[i]))
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

int	ft_check_flags(t_print *tab, const char *str, int i)
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
	return (i);
}

int	initial_str_loop(t_print *tab, const char *str, int i)
{
	while (str[i] != '%' && str[i] != 'c' && str[i] != 's' && str[i] != 'i' && \
		str[i] != 'd' && str[i] != 'p' && str[i] != 'u' && str[i] != 'x' && \
		str[i] != 'X')
	{
		i = ft_check_flags(tab, str, i);
		if (str[i] == '#')
		{
			tab->cardinal = 1;
			i++;
		}
		if (str[i] == ' ')
		{
			tab->space = 1;
			i++;
		}
		if (str[i] == '+')
		{
			tab->plus = 1;
			i++;
		}
		if (str[i] != '0')
			i = process_width(tab, str, i);
	}
	return (i);
}
