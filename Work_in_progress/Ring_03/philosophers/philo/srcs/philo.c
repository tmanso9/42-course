/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:52:19 by touteiro          #+#    #+#             */
/*   Updated: 2023/01/26 17:52:38 by touteiro         ###   ########.fr       */
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
		if (philo->index % 2)
			my_usleep(2);
		if (!dead())
			print_message(philo, THINK);
		if (philo->left)
			pthread_mutex_lock(philo->left);
		if (philo->left)
			print_message(philo, FORK);
		if (philo->right)
			pthread_mutex_lock(philo->right);
		else
		{
			my_usleep(table()->ttd);
			print_message(philo, DIE);
		}
		if (!dead() && philo->right)
			print_message(philo, FORK);
		if (!dead())
			print_message(philo, EAT);
		if (!dead())
			my_usleep(table()->tte);
		if (philo->left)
			pthread_mutex_unlock(philo->left);
		if (philo->right)
			pthread_mutex_unlock(philo->right);
		if (!dead())
			print_message(philo, SLEEP);
		if (!dead())
			my_usleep(table()->tts);
		if (dead())
			return (NULL);
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
		gettimeofday(&start, NULL);
		table()->start_time = (start.tv_sec * (__uint64_t)1000) + \
			(start.tv_usec / (__uint64_t)1000);
		table()->dead = 0;
		i = 0;
		while (i < table()->total)
		{
			give_forks(i);
			table()->philo[i].index = i;
			table()->philo[i].last_eaten = table()->start_time;
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
