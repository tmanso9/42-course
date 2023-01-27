/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:52:19 by touteiro          #+#    #+#             */
/*   Updated: 2023/01/27 13:41:56 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_table	*table(void)
{
	static t_table	t;

	return (&t);
}

void	*run(void *data)
{
	t_philo		*philo;

	philo = data;
	while (1)
	{
		if (dead() || all_eaten())
			return (NULL);
		if (!dead())
			print_message(philo, THINK, get_time());
		if (!pickup_forks(philo))
			return (NULL);
		eat(philo);
		do_sleep(philo);
		// if (dead())
		// 	return (NULL);
	}
	return (NULL);
}

int	check_starvation(void)
{
	int			i;
	__uint64_t	moment;
	__uint64_t	diff;

	i = 0;
	moment = get_time();
	while (i < table()->total)
	{
		pthread_mutex_lock(table()->status);
		if (moment > table()->ttd && !table()->philo[i].times_eaten)
		{
			print_message(&table()->philo[i], DIE, moment);
			return (1);
		}
		pthread_mutex_unlock(table()->status);
		i++;
	}
	i = 0;
	while (i < table()->total)
	{
		pthread_mutex_lock(table()->status);
		if (moment <= table()->philo[i].last_eaten)
		{
			pthread_mutex_unlock(table()->status);
			i++;
			continue ;
		}
		diff = moment - table()->philo[i].last_eaten;
		if (diff > (table()->ttd + 10))
		{
			print_message(&table()->philo[i], DIE, moment);
			return (1);
		}
		pthread_mutex_unlock(table()->status);
		i++;
	}
	return (0);
}

int	main(int argc, char**argv)
{
	int			i;
	t_time		start;

	if (argc > 1 && argc < 7)
	{
		if (parse_args(argv, table()) == EXIT_FAILURE)
		{
			free_all(table());
			return (EXIT_FAILURE);
		}
		gettimeofday(&start, NULL);
		table()->start_time = (start.tv_sec * (__uint64_t)1000) + \
			(start.tv_usec / (__uint64_t)1000);
		table()->dead = 0;
		i = 0;
		while (i < table()->total)
		{
			give_forks(i);
			table()->philo[i].index = i;
			table()->philo[i].last_eaten = 0;
			// if (i % 2)
			// 	my_usleep(2);
			if (pthread_create(&(table()->philo[i].philo), NULL, run, \
				&table()->philo[i]))
				return (EXIT_FAILURE);
			// printf("Thread %d has started\n", i);
			i++;
		}
		while (1)
		{
			if (check_starvation() || all_eaten())
			{
				i = 0;
				while (i < table()->total)
				{
					if (pthread_join(table()->philo[i].philo, NULL))
						return (EXIT_FAILURE);
					// printf("Thread %d has finished execution\n", i);
					i++;
				}
				break ;
			}
		}
		i = 0;
		while (i++ < table()->total)
			pthread_mutex_destroy(&table()->forks[i]);
		pthread_mutex_destroy(table()->status);
		free(table()->philo);
		free(table()->forks);
		return (EXIT_SUCCESS);
	}
	else
	{
		printf("Insufficient arguments\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
