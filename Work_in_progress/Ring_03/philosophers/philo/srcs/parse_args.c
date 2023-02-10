/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:26:59 by touteiro          #+#    #+#             */
/*   Updated: 2023/02/10 14:58:51 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	start_table(t_table *table, char **argv)
{
	table->total = ft_atoi(argv[1]);
	table->ttd = ft_atoi(argv[2]);
	table->tte = ft_atoi(argv[3]);
	table->tts = ft_atoi(argv[4]);
	if (argv[5])
	{
		table->min_times = ft_atoi(argv[5]);
		if (!table->min_times)
			return (EXIT_FAILURE);
		table->unlimited = 0;
	}
	else
		table->unlimited = 1;
	table->philo = ft_calloc(sizeof(t_philo), table->total);
	table->forks = ft_calloc(sizeof(pthread_mutex_t), table->total);
	table->status = ft_calloc(sizeof(pthread_mutex_t), 1);
	if (!table->philo || !table->forks || !table->status)
		return (EXIT_FAILURE);
	if (pthread_mutex_init(table->status, NULL))
		return (EXIT_FAILURE);
	if (pthread_mutex_init(&table->printing, NULL))
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
		if (pthread_mutex_init(&table->forks[i], NULL) != 0)
			return (EXIT_FAILURE);
		if (pthread_mutex_init(&table->philo[i].eating, NULL) != 0)
			return (EXIT_FAILURE);
		if (pthread_mutex_init(&table->philo[i].check_full, NULL) != 0)
			return (EXIT_FAILURE);
		give_forks(i);
		table->philo[i].index = i;
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
