/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:52:19 by touteiro          #+#    #+#             */
/*   Updated: 2023/01/24 00:32:01 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_table	*table(void)
{
	static t_table	t;

	return (&t);
}

void	*example(void *data)
void	*run(void *data)
{
	int		i;
	t_arr	*thread;
	int		i;
	t_philo	*philo;
	t_time	curr;

	thread = data;
	philo = data;
	i = 0;
	if (philo->index % 2)
		my_usleep(10);
	while (i++ < 1)
	{
		pthread_mutex_lock(&(thread->mutex));
		(thread->mails)++;
		pthread_mutex_unlock(&(thread->mutex));
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
	free(thread->index);
	return (NULL);
}

int	main(int argc, char**argv)
{
	pthread_t		*th;
	t_arr			arr;
	int				i;
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
	pthread_mutex_destroy(&arr.mutex);
	free(th);
	printf("Number of mails: %d\n", arr.mails);
	return (EXIT_SUCCESS);
}
