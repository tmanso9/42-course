/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:52:19 by touteiro          #+#    #+#             */
/*   Updated: 2023/01/25 22:12:24 by touteiro         ###   ########.fr       */
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
	int			i;
	t_philo		*philo;

	philo = data;
	i = 0;
	while (i++ < 100)
	{
		if (philo->index % 2)
			my_usleep(10);
		if (!philo->dead && philo->left)
			pthread_mutex_lock(philo->left);
		if (!philo->dead)
			print_message(philo, FORK);
		if (!philo->dead && philo->right)
			pthread_mutex_lock(philo->right);
		else
		{
			my_usleep(table()->ttd);
			print_message(philo, DIE);
		}
		if (!philo->dead)
			print_message(philo, FORK);
		if (!philo->dead)
			print_message(philo, EAT);
		if (!philo->dead)
			my_usleep(table()->tte);
		if (!philo->dead)
			pthread_mutex_unlock(philo->left);
		if (!philo->dead)
			pthread_mutex_unlock(philo->right);
		if (!philo->dead)
			print_message(philo, SLEEP);
		if (!philo->dead)
			my_usleep(table()->tts);
		if (!philo->dead)
			print_message(philo, THINK);
	}
	return (NULL);
}

int	main(int argc, char**argv)
{
	int		i;
	t_time	start;

	if (argc > 1 && argc < 7)
	{
		if (parse_args(argv, table()) == EXIT_FAILURE)
		{
			free_all(table());
			return (EXIT_FAILURE);
		}
		i = 0;
		while (i < table()->total)
		{
			give_forks(i);
			table()->philo[i].index = i;
			gettimeofday(&start, NULL);
			table()->philo[i].start_time = (start.tv_sec * (__uint64_t)1000) + \
				(start.tv_usec / (__uint64_t)1000);
			table()->philo[i].last_eaten = table()->philo[i].start_time;
			table()->philo[i].times_eaten = 0;
			table()->philo[i].dead = 0;
			if (pthread_create(&(table()->philo[i].philo), NULL, run, \
				&table()->philo[i]))
				return (EXIT_FAILURE);
			// printf("Thread %d has started\n", i);
			i++;
		}
		i = 0;
		while (i < table()->total)
		{
			if (pthread_join(table()->philo[i].philo, NULL))
				return (EXIT_FAILURE);
			// printf("Thread %d has finished execution\n", i);
			i++;
		}
		i = 0;
		while (i++ < table()->total)
			pthread_mutex_destroy(&table()->forks[i]);
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
