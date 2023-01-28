/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:26:59 by touteiro          #+#    #+#             */
/*   Updated: 2023/01/28 02:03:13 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	numeric(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
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
			if (!numeric(argv[i][j++]))
			{
				if (i == 1)
					printf("\nInvalid number of philosophers\n");
				else if (i < 5)
					printf("\nInvalid time argument\n");
				else
					printf("\nInvalid number of times to eat\n");
				print_usage();
				return (0);
			}
		}
	}
	return (1);
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

int	check_range(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if ((i == 1 && ft_strlen(argv[i]) > 3 && \
			printf("\nNumber of philosophers too high\n")) || \
			(((argv[i][0] != '-' && ft_strlen(argv[i]) > 10) || \
			(ft_strlen(argv[i]) > 9 && \
			strncmp("2147483647", argv[i], 11) < 0)) && \
			printf("\nNumber too high\n")) || \
			((argv[i][0] == '-' && \
			printf("\nNumbers can't be negative values\n"))))
			return (print_usage());
		i++;
	}
	return (1);
}

static int	args_valid(char **argv)
{
	if (!check_numeric(argv) || !check_range(argv))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	parse_args(char **argv, t_table *table)
{
	int		i;

	if (args_valid(argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	table->total = ft_atoi(argv[1]);
	table->ttd = ft_atoi(argv[2]);
	table->tte = ft_atoi(argv[3]);
	table->tts = ft_atoi(argv[4]);
	if (argv[5])
		table->min_times = ft_atoi(argv[5]);
	else
		table->min_times = 1000;
	table->philo = ft_calloc(sizeof(t_philo) * table->total, 1);
	table->forks = ft_calloc(sizeof(pthread_mutex_t) * table->total, 1);
	table->status = ft_calloc(sizeof(pthread_mutex_t), 1);
	if (!table->philo || !table->forks || !table->status)
		return (EXIT_FAILURE);
	i = 0;
	if (pthread_mutex_init(table->status, NULL))
		return (EXIT_FAILURE);
	while (i < table->total)
	{
		table->philo[i].times_eaten = 0;
		table->philo[i].thinked = 0;
		if (pthread_mutex_init(&table->forks[i++], NULL) != 0)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
