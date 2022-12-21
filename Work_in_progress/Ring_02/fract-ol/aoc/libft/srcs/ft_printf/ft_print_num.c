/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:56:59 by touteiro          #+#    #+#             */
/*   Updated: 2022/11/29 19:27:02 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

static int	count_digits(unsigned int n)
{
	int	digits;

	digits = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		count_digits(n = n / 10);
		digits++;
	}
	return (digits);
}

/*
Allocates (with malloc(3)) and returns a string
representing the integer received as an argument.
Negative numbers must be handled.
*/
static char	*ft_uitoa(unsigned int n)
{
	char				*str;
	int					digits;
	unsigned long int	long_n;

	digits = count_digits(n);
	str = (char *)malloc(sizeof(char) * (digits + 1));
	if (!str)
		return (NULL);
	long_n = n;
	if (long_n == 0)
		str[0] = '0';
	str[digits] = '\0';
	while (long_n != 0)
	{
		str[digits - 1] = (long_n % 10) + '0';
		long_n = long_n / 10;
		digits--;
	}
	return (str);
}

static void	ft_process_no_flags(t_print *tab, char *str, int len)
{
	if ((tab->plus || tab->space) && str[0] != '-')
	{
		if (tab->plus)
			ft_putchar_fd('+', 1);
		else if (tab->space)
			ft_putchar_fd(' ', 1);
		tab->printed += 1;
	}
	ft_putstr_fd(str, 1);
	tab->printed += len;
}

/*
%d or %i: The int (or appropriate variant) argument is converted to
signed decimal (d and i) notation.
*/
int	ft_print_i(t_print *tab)
{
	char	*str;
	int		len;
	int		i;

	str = ft_itoa(va_arg(tab->args, int));
	if (!str)
		return (-1);
	len = ft_strlen(str);
	i = -1;
	if (tab->dot || tab->dash || tab->width || tab->zero)
	{
		if (tab->dash)
			ft_process_i_dash(tab, str, len, i);
		else if (tab->zero || tab->width)
			ft_process_i_width(tab, str, len, i);
		else
			ft_process_i_dot(tab, str, len, i);
	}
	else
		ft_process_no_flags(tab, str, len);
	free (str);
	return (1);
}

int	ft_print_u(t_print *tab)
{
	char	*str;
	int		len;
	int		i;

	str = ft_uitoa(va_arg(tab->args, unsigned int));
	len = ft_strlen(str);
	if (!len)
		return (0);
	i = -1;
	if (tab->dot || tab->dash || tab->width || tab->zero)
	{
		if (tab->dash)
			ft_process_i_dash(tab, str, len, i);
		else if (tab->zero || tab->width)
			ft_process_i_width(tab, str, len, i);
		else
			ft_process_i_dot(tab, str, len, i);
	}
	else
	{
		ft_putstr_fd(str, 1);
		tab->printed += len;
	}
	free (str);
	return (1);
}
