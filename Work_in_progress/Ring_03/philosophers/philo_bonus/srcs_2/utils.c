/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:17:11 by touteiro          #+#    #+#             */
/*   Updated: 2023/02/03 11:35:12 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
	start = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	end = start + milisec;
	while (start < end)
	{
		gettimeofday(&tv, NULL);
		start = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
		usleep(50);
	}
}

__uint64_t	get_time(void)
{
	struct timeval	curr;
	__uint64_t		ms;

	gettimeofday(&curr, NULL);
	ms = (curr.tv_sec * (__uint64_t)1000) + (curr.tv_usec / (__uint64_t)1000);
	return (ms - table()->start_time);
}

int	print_message(t_philo *philo, int status, __uint64_t time)
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
	{
		printf("%lu %d died\n", time, philo->index + 1);
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
	}
}

int	dead(void)
{
	int	status;

	status = 0;
	pthread_mutex_lock(table()->status);
	status = table()->dead;
	pthread_mutex_unlock(table()->status);
	return (status);
}

int	full(void)
{
	int	status;

	status = 0;
	pthread_mutex_lock(table()->status);
	status = table()->all_full;
	pthread_mutex_unlock(table()->status);
	return (status);
}

int	all_eaten(void)
{
	int	i;
	int	full;

	i = 0;
	full = 0;
	if (table()->unlimited)
		return (0);
	while (i < table()->total)
	{
		pthread_mutex_lock(&table()->philo[i].check_full);
		full = table()->philo[i].full_belly;
		pthread_mutex_unlock(&table()->philo[i].check_full);
		if (!full)
			return (0);
		i++;
	}
	pthread_mutex_lock(table()->status);
	table()->all_full = 1;
	pthread_mutex_unlock(table()->status);
	return (1);
}

int	print_usage(void)
{
	printf("Usage: \n\t./philo <number_of_philosophers> <time_to_die> ");
	printf("<time_to_eat> <time_to_sleep> [optional: ");
	printf("number_of_times_each_philosopher_must_eat]\n\n");
	return (0);
}