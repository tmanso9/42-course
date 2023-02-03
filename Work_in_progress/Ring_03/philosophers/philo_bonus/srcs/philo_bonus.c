/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:52:19 by touteiro          #+#    #+#             */
/*   Updated: 2023/02/03 11:30:49 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

t_table	*table(void)
{
	static t_table	t;

	return (&t);
}

void	*run(void *data)
{
	t_philo		*philo;

	philo = data;
	if (philo->index % 2)
		my_usleep(10);
	while (!dead() && !full())
	{
		// if (!dead() && !full()() && !philo->thinked)
		// {
		// 	philo->thinked = 1;
		// 	print_message(philo, THINK, get_time());
		// }
		if (!pickup_forks(philo))
			return (NULL);
		eat(philo);
		do_sleep(philo);
		if (!dead() && !full())
			print_message(philo, THINK, get_time());
	}
	return (NULL);
}

int	check_starvation(void)
{
	int			i;
	__uint64_t	moment;
	__uint64_t	diff;
	__uint64_t	last_ate;

	i = -1;
	moment = get_time();
	// while (++i < table()->total)
	// {
	// 	pthread_mutex_lock(table()->status);
	// 	if (moment > table()->ttd && !table()->philo[i].times_eaten)
	// 		return (print_message(&table()->philo[i], DIE, moment));
	// 	pthread_mutex_unlock(table()->status);
	// }
	// i = -1;
	while (++i < table()->total)
	{
		pthread_mutex_lock(&table()->philo[i].eating);
		last_ate = table()->philo[i].last_eaten;
		pthread_mutex_unlock(&table()->philo[i].eating);
		if (moment <= last_ate)
			continue ;
		diff = moment - last_ate;
		if (diff >= (table()->ttd))
		{
			pthread_mutex_lock(table()->status);
			table()->dead = 1;
			pthread_mutex_unlock(table()->status);
			return (print_message(&table()->philo[i], DIE, moment));
		}
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
			if (pthread_create(&(table()->philo[i].philo), NULL, run, \
				&table()->philo[i]))
				return (EXIT_FAILURE);
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
					i++;
				}
				break ;
			}
		}
		// pthread_mutex_destroy(table()->check_full);
		i = -1;
		while (++i < table()->total)
		{
			pthread_mutex_destroy(&table()->forks[i]);
			pthread_mutex_destroy(&table()->philo[i].eating);
			pthread_mutex_destroy(&table()->philo[i].check_full);
		}
		pthread_mutex_destroy(table()->status);
		free_all(table());
		return (EXIT_SUCCESS);
	}
	else
	{
		printf("Invalid number of arguments\n");
		print_usage();
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
