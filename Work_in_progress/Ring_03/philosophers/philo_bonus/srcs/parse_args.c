/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:26:59 by touteiro          #+#    #+#             */
/*   Updated: 2023/02/05 12:18:44 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	start_table(t_table *table, char **argv)
{
	table->total = ft_atoi(argv[1]);
	table->ttd = ft_atoi(argv[2]);
	table->tte = ft_atoi(argv[3]);
	table->tts = ft_atoi(argv[4]);
	table->i = 1;
	if (argv[5])
	{
		table->min_times = ft_atoi(argv[5]);
		table->unlimited = 0;
		if (!table->min_times)
			return (EXIT_FAILURE);
	}
	else
		table->unlimited = 1;
	table->philo = ft_calloc(sizeof(t_philo), table->total);
	if (!table->philo)
		return (EXIT_FAILURE);
	// table->forks = ft_calloc(sizeof(sem_t *), 1);
	// if (!table->forks)
		// return (EXIT_FAILURE);
	table->forks = sem_open("/forks", O_CREAT, 0666, table->total / 2);
	if (table->forks == SEM_FAILED)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	start_philos(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->total)
	{
		table->philo[i].times_eaten = 0;
		table->philo[i].last_eaten = 0;
		i++;
	}
	return (EXIT_SUCCESS);
}

int	parse_args(char **argv, t_table *table)
{
	if (args_valid(argv) == EXIT_FAILURE || \
		start_table(table, argv) == EXIT_FAILURE || \
		start_philos(table) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
