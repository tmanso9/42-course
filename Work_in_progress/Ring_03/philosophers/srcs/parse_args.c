/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:26:59 by touteiro          #+#    #+#             */
/*   Updated: 2023/01/23 18:53:07 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parse_args(char **argv, t_table *table)
{
	int	i;

	table->total = ft_atoi(argv[1]);
	table->ttd = ft_atoi(argv[2]);
	table->tte = ft_atoi(argv[3]);
	table->tts = ft_atoi(argv[4]);
	if (argv[5])
		table->min_times = ft_atoi(argv[5]);
	else
		table->min_times = 1;
	table->philo = ft_calloc(sizeof(t_philo) * table->total, 1);
	table->forks = ft_calloc(sizeof(pthread_mutex_t) * table->total, 1);
	if (!table->philo || !table->forks)
		return (EXIT_FAILURE);
	i = 0;
	while (i++ < table->total)
	{
		if (pthread_mutex_init(&table->forks[i], NULL) != 0)
			return (EXIT_FAILURE);
	}
	gettimeofday(&table->start_time, NULL);
	return (EXIT_SUCCESS);
}
