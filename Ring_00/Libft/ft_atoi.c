/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 19:28:38 by touteiro          #+#    #+#             */
/*   Updated: 2022/10/07 20:12:05 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

static unsigned int	process_num(const char *str, unsigned int res)
{
	int	i;

	i = 0;
	while (ft_isdigit(str[i]))
	{
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
