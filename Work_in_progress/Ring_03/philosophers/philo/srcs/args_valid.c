/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_valid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:57:04 by touteiro          #+#    #+#             */
/*   Updated: 2023/02/04 16:16:03 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (2048);
	else
		return (0);
}

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

static int	check_numeric(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[++i])
	{
		j = 0;
		if (argv[i][0] == '-' || argv[i][0] == '+')
			j++;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j++]))
			{
				if (i == 1)
					write(2, "\nInvalid number of philosophers\n", 32);
				else if (i < 5)
					write(2, "\nInvalid time argument\n", 23);
				else
					write(2, "\nInvalid number of times to eat\n", 32);
				return (print_usage());
			}
		}
	}
	return (1);
}

static int	check_range(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (i == 1 && ft_strlen(argv[i] + (argv[i][0] == '-')) > 3)
			if (write(2, "\nNumber of philosophers too high\n", 33))
				return (print_usage());
		if ((argv[i][0] != '-' && ft_strlen(argv[i]) > 10) || \
			(ft_strlen(argv[i]) > 9 && strncmp("2147483647", argv[i], 11) < 0))
			if (write(2, "\nNumber too high\n", 17))
				return (print_usage());
		if (argv[i][0] == '-')
			if (write(2, "\nArguments can't be negative values\n", 36))
				return (print_usage());
		i++;
	}
	return (1);
}

int	args_valid(char **argv)
{
	int	i;

	i = 0;
	while (argv[++i])
	{
		if (!ft_strlen(argv[i]))
		{
			write(2, "\nEmpty argument\n", 16);
			print_usage();
			return (EXIT_FAILURE);
		}
	}
	if (!check_numeric(argv) || !check_range(argv))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
