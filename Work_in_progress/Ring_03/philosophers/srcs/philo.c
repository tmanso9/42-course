/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:52:19 by touteiro          #+#    #+#             */
/*   Updated: 2023/01/23 19:22:19 by touteiro         ###   ########.fr       */
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
	int		i;
	t_philo	*philo;
	t_time	curr;

	philo = data;
	i = 0;
	if (philo->index % 2)
		my_usleep(10);
	while (i++ < 1)
	{
		if (philo->index % 2)
		{
			pthread_mutex_lock(philo->left);
			pthread_mutex_lock(philo->right);
			gettimeofday(&curr, NULL);
			printf("Philosopher %d did stuff at %ld\n", philo->index + 1, (curr.tv_usec - table()->start_time.tv_usec) / 1000);
			pthread_mutex_unlock(philo->left);
			pthread_mutex_unlock(philo->right);
		}
		else
		{
			pthread_mutex_lock(philo->right);
			pthread_mutex_lock(philo->left);
			gettimeofday(&curr, NULL);
			printf("Philosopher %d did stuff at %ld\n", philo->index + 1, (curr.tv_usec - table()->start_time.tv_usec) / 1000);
			pthread_mutex_unlock(philo->right);
			pthread_mutex_unlock(philo->left);
		}
	}
	return (NULL);
}

int	main(int argc, char**argv)
{
	int		i;

	if (argc > 1 && argc < 7)
	{

		if (parse_args(argv, table()) != 0)
		{
			free_all(table());
			return (EXIT_FAILURE);
		}
		i = 0;
		while (i < table()->total)
		{
			table()->philo[i].left = &table()->forks[i % table()->total];
			table()->philo[i].right = &table()->forks[(i + 1) % table()->total];
			table()->philo[i].index = i;
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
}
