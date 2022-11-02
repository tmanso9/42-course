/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:29:09 by touteiro          #+#    #+#             */
/*   Updated: 2022/10/20 12:24:08 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_normal_char(char c)
{
	write(1, &c, 1);
	return (1);
}

static int	ft_print_percent(void)
{
	write(1, "%", 1);
	return (1);
}

static int	ft_formats(va_list args, char c, int count, int *i)
{
	if (c == '%')
		count += ft_print_percent();
	else if (c == 'c')
		count += ft_print_c(va_arg(args, int));
	else if (c == 's')
		count += ft_print_s(va_arg(args, char *));
	else if (c == 'i' || c == 'd')
		count += ft_print_i(va_arg(args, int));
	else if (c == 'p')
		count += ft_print_ptr(va_arg(args, uintptr_t));
	else if (c == 'u')
		count += ft_print_u(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		count += ft_print_x(va_arg(args, unsigned int), c);
	else
		(*i)--;
	return (count);
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
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			count = ft_formats(args, str[i + 1], count, &i);
			i++;
		}
		else
			count += ft_print_normal_char(str[i]);
		i++;
	}
	va_end(args);
	return (count);
}
