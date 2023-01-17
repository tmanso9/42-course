/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:56:59 by touteiro          #+#    #+#             */
/*   Updated: 2022/11/29 19:27:05 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

static int	ptr_digits(uintptr_t i)
{
	int	digits;

	digits = 0;
	while (i > 0)
	{
		i /= 16;
		digits++;
	}
	return (digits);
}

/*
Useful types provided by <inttypes.h> include signed and unsigned
integer types large enough to hold a pointer. These are given as intptr_t
and uintptr_t. In addition, intmax_t and uintmax_t are defined to be the
longest (in bits) signed and unsigned integer types available.
*/
static void	ft_putptr(uintptr_t i)
{
	if (i < 16)
	{
		if (i < 10)
			ft_putchar_fd(i + '0', 1);
		else
			ft_putchar_fd(i - 10 + 'a', 1);
	}
	if (i >= 16)
	{
		ft_putptr(i / 16);
		ft_putptr(i % 16);
	}
}

static void	ft_process_no_ptr(t_print *tab, int count)
{
	if (tab->width > 5 && !tab->dash)
	{
		while (++count < (tab->width - 5))
			write(1, " ", 1);
		tab->printed += tab->width;
	}
	ft_putstr_fd("(nil)", 1);
	if (tab->width > 5 && tab->dash)
	{
		while (++count < (tab->width - 5))
			write(1, " ", 1);
		tab->printed += tab->width;
	}
	if (tab->width <= 5)
		tab->printed += 5;
}

static void	ft_process_ptr(t_print *tab, uintptr_t i, int len, int count)
{
	if (tab->width > (ptr_digits(i) + 2) && !tab->dash)
	{
		while (++count < (tab->width - ptr_digits(i) - 2))
			write(1, " ", 1);
		tab->printed += tab->width;
	}
	ft_putstr_fd("0x", 1);
	len = 2;
	ft_putptr(i);
	if (tab->width > (ptr_digits(i) + 2) && tab->dash)
	{
		while (++count < (tab->width - ptr_digits(i) - 2))
			write(1, " ", 1);
		tab->printed += tab->width;
	}
	if (tab->width <= (ptr_digits(i) + 2))
		tab->printed += len + ptr_digits(i);
}

/*
%d or %i: The int (or appropriate variant) argument is converted to
signed decimal (d and i) notation.
*/
int	ft_print_ptr(t_print *tab)
{
	int			len;
	uintptr_t	i;
	int			count;

	count = -1;
	len = 0;
	i = va_arg(tab->args, uintptr_t);
	if (!i)
	{
		ft_process_no_ptr(tab, count);
		return (1);
	}
	ft_process_ptr(tab, i, len, count);
	return (1);
}
