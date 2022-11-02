/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:56:59 by touteiro          #+#    #+#             */
/*   Updated: 2022/11/02 16:47:04 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	static int	count;

	count = 0;
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

/*
%d or %i: The int (or appropriate variant) argument is converted to
signed decimal (d and i) notation.
*/
int	ft_print_ptr(uintptr_t i)
{
	int	len;

	if (!i)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	ft_putstr_fd("0x", 1);
	len = 2;
	if (i == 0)
	{
		ft_putchar_fd('0', 1);
		return (len + 1);
	}
	else
	{
		ft_putptr(i);
		return (len + ptr_digits(i));
	}
}
