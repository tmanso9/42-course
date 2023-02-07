/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:17:11 by touteiro          #+#    #+#             */
/*   Updated: 2023/02/07 19:20:10 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	msg_out(__uint64_t time, t_philo *philo, int status)
{
	if (status == FORK)
		printf("%lu %d has taken a fork\n", time, philo->index + 1);
	if (status == EAT)
		printf("%lu %d is eating\n", time, philo->index + 1);
	if (status == SLEEP)
		printf("%lu %d is sleeping\n", time, philo->index + 1);
	if (status == THINK)
		printf("%lu %d is thinking\n", time, philo->index + 1);
	if (status == DIE)
		printf("%lu %d died\n", time, philo->index + 1);
}

int	print_message(t_philo *philo, int status, __uint64_t time)
{
	if (status != DIE)
	{
		pthread_mutex_lock(&table()->printing);
		msg_out(time, philo, status);
		pthread_mutex_unlock(&table()->printing);
	}
	else
	{
		pthread_mutex_lock(&table()->printing);
		msg_out(time, philo, status);
		pthread_mutex_unlock(&table()->printing);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	print_usage(void)
{
	printf("Usage: \n\t./philo <number_of_philosophers> <time_to_die> ");
	printf("<time_to_eat> <time_to_sleep> [optional: ");
	printf("number_of_times_each_philosopher_must_eat]\n\n");
	return (0);
}

void	free_all(t_table *table)
{
	if (table)
	{
		if (table->philo)
			free(table->philo);
		if (table->forks)
			free(table->forks);
		if (table->status)
			free(table->status);
	}
}

void	mutexes_destroy(void)
{
	int	i;

	i = -1;
	while (++i < table()->total)
	{
		pthread_mutex_destroy(&table()->forks[i]);
		pthread_mutex_destroy(&table()->philo[i].eating);
		pthread_mutex_destroy(&table()->philo[i].check_full);
	}
	pthread_mutex_destroy(table()->status);
	pthread_mutex_destroy(&table()->printing);
}
