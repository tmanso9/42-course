/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:17:11 by touteiro          #+#    #+#             */
/*   Updated: 2023/01/26 11:38:16 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (2048);
	else
		return (0);
}

void	my_usleep(int milisec)
{
	struct timeval	tv;
	__uint64_t		start;
	__uint64_t		end;

	gettimeofday(&tv, NULL);
	start = (tv.tv_sec * (__uint64_t)1000) + (tv.tv_usec / (__uint64_t)1000);
	end = start + milisec;
	while (start < end)
	{
		gettimeofday(&tv, NULL);
		start = (tv.tv_sec * (__uint64_t)1000) + (tv.tv_usec / (__uint64_t)1000);
	}
}

int	print_message(t_philo *philo, int status)
{
	t_time		curr;
	__uint64_t	ms;
	__uint64_t	diff;

	if (dead())
		return (EXIT_FAILURE);
	gettimeofday(&curr, NULL);
	ms = (curr.tv_sec * (__uint64_t)1000) + (curr.tv_usec / (__uint64_t)1000);
	diff = ms - table()->start_time;
	if (status != DIE && (ms - philo->last_eaten) > ((table()->ttd + 10)))
	{
		print_message(philo, DIE);
		return (EXIT_FAILURE);
	}
	if (status == FORK)
		printf("%lu %d has taken a fork\n", diff, philo->index + 1);
	if (status == EAT)
	{
		gettimeofday(&curr, NULL);
		philo->last_eaten = (curr.tv_sec * (__uint64_t)1000) + (curr.tv_usec / (__uint64_t)1000);
		philo->times_eaten++;
		printf("%lu %d is eating\n", diff, philo->index + 1);
	}
	if (status == SLEEP)
		printf("%lu %d is sleeping\n", diff, philo->index + 1);
	if (status == THINK)
		printf("%lu %d is thinking\n", diff, philo->index + 1);
	if (status == DIE)
	{
		// if (philo->left)
		// 	pthread_mutex_unlock(philo->left);
		// if (philo->right)
		// 	pthread_mutex_unlock(philo->right);
		pthread_mutex_lock(table()->status);
		table()->dead = 1;
		pthread_mutex_unlock(table()->status);
		printf("%lu %d has died\n", diff, philo->index + 1);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
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
		free(table);
	}
}

int	dead(void)
{
	int	status;

	pthread_mutex_lock(table()->status);
	status = table()->dead;
	pthread_mutex_unlock(table()->status);
	return (status);
}

int	all_eaten(void)
{
	int	i;
	int	eaten;

	i = 0;
	eaten = 0;
	pthread_mutex_lock(table()->status);
	while (i < table()->total)
	{
		if (table()->philo->times_eaten == table()->min_times)
			eaten++;
		i++;
	}
	pthread_mutex_unlock(table()->status);
	if (eaten == table()->total)
		return (1);
	return (0);
}
