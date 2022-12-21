/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:29:09 by touteiro          #+#    #+#             */
/*   Updated: 2022/12/09 16:34:24 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

static int	ft_print_normal_char(char c)
{
	write(1, &c, 1);
	return (1);
}

static int	ft_print_percent(t_print *tab)
{
	write(1, "%", 1);
	tab->printed += 1;
	return (1);
}

static int	ft_formats(t_print *tab, const char *str, int i)
{
	initialize_struct(tab);
	i = initial_str_loop(tab, str, i);
	if (str[i] == '%')
		i += ft_print_percent(tab);
	else if (str[i] == 'c')
		i += ft_print_c(tab);
	else if (str[i] == 's')
		i += ft_print_s(tab);
	else if (str[i] == 'i' || str[i] == 'd')
		i += ft_print_i(tab);
	else if (str[i] == 'p')
		i += ft_print_ptr(tab);
	else if (str[i] == 'u')
		i += ft_print_u(tab);
	else if (str[i] == 'x' || str[i] == 'X')
		i += ft_print_x(tab, str[i]);
	return (i);
}

static int	ft_check_str(const char *str, int i, t_print *tab)
{
	if (str[i] == '%')
	{
		i++;
		i = ft_formats(tab, str, i);
	}
	else
	{
		tab->printed += ft_print_normal_char(str[i]);
		i++;
	}
	return (i);
}

/*
%p: The void * pointer argument is printed in hexadecimal
(as if by `%#x' or `%#lx').

%u: The int (or appropriate variant) argument is converted to unsigned
decimal (u) notation.

%x or %X: The int (or appropriate variant) argument is converted to
unsigned hexadecimal (x and X) notation. x is lowercase, X uppercase.

RETURN VALUE: number of characters printed (not including the trailing
`\0' used to end output to strings). A negative value if an error occurs.
*/
int	ft_printf(const char *str, ...)
{
	t_print	*tab;
	int		i;
	int		printed;

	i = 0;
	tab = (t_print *)malloc(sizeof(t_print));
	if (!tab)
		return (-1);
	tab->printed = 0;
	va_start(tab->args, str);
	while (str[i])
		i = ft_check_str(str, i, tab);
	va_end(tab->args);
	printed = tab->printed;
	free(tab);
	return (printed);
}
