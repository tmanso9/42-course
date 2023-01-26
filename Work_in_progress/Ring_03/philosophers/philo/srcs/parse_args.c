/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:26:59 by touteiro          #+#    #+#             */
/*   Updated: 2023/01/26 17:32:53 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parse_args(char **argv, t_table *table)
{
	int		i;

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
		if (pthread_mutex_init(&table->forks[i++], NULL) != 0)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
