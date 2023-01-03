/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_text.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:56:59 by touteiro          #+#    #+#             */
/*   Updated: 2022/11/29 19:27:09 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

/*
%c: The int argument is converted to an unsigned char,
and the resulting character is written.
*/
int	ft_print_c(t_print *tab)
{
	char			c;
	unsigned char	un_c;
	int				i;

	c = va_arg(tab->args, int);
	un_c = (unsigned char)c;
	i = -1;
	if (tab->width && !tab->dash)
	{
		while (++i < tab->width - 1)
			ft_putchar_fd(' ', 1);
		tab->printed += tab->width - 1;
	}
	write(1, &un_c, 1);
	tab->printed += 1;
	if (tab->width && tab->dash)
	{
		while (++i < tab->width - 1)
			ft_putchar_fd(' ', 1);
		tab->printed += tab->width - 1;
	}
	return (1);
}

static void	ft_process_no_dot(t_print *tab, char *str, int i, int len)
{
	if (tab->width > len)
	{
		if (!tab->dash)
		{
			while (++i < (tab->width - len))
				ft_putchar_fd(' ', 1);
			i = -1;
		}
		ft_putstr_fd(str, 1);
		if (tab->dash)
		{
			while (++i < (tab->width - len))
				ft_putchar_fd(' ', 1);
		}
		tab->printed += tab->width;
	}
	else
	{
		ft_putstr_fd(str, 1);
		tab->printed += len;
	}
}

static void	ft_process_dot(t_print *tab, char *str, int i)
{
	if (tab->width > tab->precision && !tab->dash)
	{
		while (++i < (tab->width - tab->precision))
			ft_putchar_fd(' ', 1);
		i = -1;
	}
	while (++i < tab->precision)
		ft_putchar_fd(str[i], 1);
	i = -1;
	if (tab->width > tab->precision && tab->dash)
	{
		while (++i < (tab->width - tab->precision))
			ft_putchar_fd(' ', 1);
	}
	tab->printed += return_biggest(tab->width, tab->precision);
}

static int	ft_process_no_str(t_print *tab, char **str, int i)
{
	if (tab->precision == -1)
		tab->precision = 0;
	if (!*str)
	{
		if (!tab->width && tab->dot && tab->precision < 6)
			return (-1);
		else if (tab->width && tab->dot && tab->precision < 6)
		{
			while (++i < tab->width)
				ft_putchar_fd(' ', 1);
			tab->printed += tab->width;
			return (-1);
		}
		else
		{
			*str = "(null)";
			return (1);
		}
	}
	return (1);
}

/*
%s: The char * argument is expected to be a pointer to an array of
character type (pointer to a string).  Characters from the array
are written up to (but not including) a terminating NUL character.
*/
int	ft_print_s(t_print *tab)
{
	char	*str;
	int		i;
	int		len;

	i = -1;
	str = va_arg(tab->args, char *);
	if (ft_process_no_str(tab, &str, i) < 0)
		return (1);
	len = ft_strlen(str);
	if (tab->precision > len)
		tab->precision = len;
	if (tab->dot || tab->dash || tab->width)
	{
		if (tab->dot)
			ft_process_dot(tab, str, i);
		else
			ft_process_no_dot(tab, str, i, len);
	}
	else
	{
		ft_putstr_fd(str, 1);
		tab->printed += len;
	}
	return (1);
}
