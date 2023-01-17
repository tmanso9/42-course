/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 19:28:38 by touteiro          #+#    #+#             */
/*   Updated: 2022/11/29 19:27:41 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

static int	is_space(char c)
{
	if (c == '\t'
		|| c == '\n'
		|| c == '\v'
		|| c == '\f'
		|| c == '\r'
		|| c == ' ')
		return (1);
	else
		return (0);
}

static int	is_operator(char c)
{
	if (c == '+' || c == '-')
		return (1);
	else
		return (0);
}

static unsigned int	count_digits(unsigned int n)
{
	unsigned int	digits;

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
We start by advancing initial zeros and counting how many we advanced.
When we enter the while loop, we check if count_digits(res) is smaller
than i because that means that res is trying to process a number
bigger than INT_MAX or smaller than INT_MIN.
We check to see if (str-count)[-1] - i.e., the char before the original
str - is a minus, because if the number < INT_MIN the original atoi returns 0,
and if it is > INT_MAX atoi returns -1.
*/
static unsigned int	process_num(const char *str, unsigned int res)
{
	unsigned int	i;
	unsigned int	count;

	i = 0;
	count = 0;
	while (str[i] == '0')
	{
		str++;
		count++;
	}
	while (ft_isdigit(str[i]))
	{
		if (count_digits(res) < i)
		{
			if ((str - count)[-1] == '-')
				return (0);
			else
				return (-1);
		}
		res *= 10;
		res += (str[i] - '0');
		i++;
	}
	return (res);
}

int	ft_atoi(const char *str)
{
	int				posneg;
	unsigned int	res;

	posneg = 1;
	res = 0;
	if (is_space(*str) || is_operator(*str) || ft_isdigit(*str))
	{
		while (is_space(*str))
			str++;
		if (is_operator(*str))
		{
			if (*str == '+' && ft_isdigit(*(str + 1)))
				str++;
			else if (*str == '-' && ft_isdigit(*(str + 1)))
			{
				posneg = -1;
				str++;
			}
			else
				return (0);
		}
		res = process_num(str, res);
	}
	return ((int)(res * posneg));
}
