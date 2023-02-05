/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:17:11 by touteiro          #+#    #+#             */
/*   Updated: 2023/02/02 20:43:58 by touteiro         ###   ########.fr       */
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
		printf("%llu %d has taken a fork\n", time, philo->index + 1);
	if (status == EAT)
		printf("%llu %d is eating\n", time, philo->index + 1);
	if (status == SLEEP)
		printf("%llu %d is sleeping\n", time, philo->index + 1);
	if (status == THINK)
		printf("%llu %d is thinking\n", time, philo->index + 1);
	if (status == DIE)
	{
		printf("%llu %d died\n", time, philo->index + 1);
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
		if (table->forks_avail)
			free(table->forks_avail);
	}
}

int	dead(void)
{
	int	status;
	int	i;

	i = -1;
	while(++i < table()->total)
	{
		pthread_mutex_lock(table()->philo[i].eating);
		status = table()->dead;
		pthread_mutex_unlock(table()->philo[i].eating);
		if (status)
			return (status);
	}
	return (status);
}

int	all_eaten(void)
{
	int	i;
	int	full;

	i = 0;
	full = 0;
	while (i < table()->total)
	{
		pthread_mutex_lock(table()->philo[i].eating);
		printf("philo %d has eaten %d times\n", table()->philo[i].index + 1, table()->philo[i].times_eaten);
		if (table()->philo[i].times_eaten >= table()->min_times)
			full++;
		pthread_mutex_unlock(table()->philo[i].eating);
		i++;
	}
	if (full == table()->total)
		return (1);
	return (0);
}

int	print_usage(void)
{
	write(2, "Usage: \n\t./philo <number_of_philosophers> <time_to_die> ", 58);
	write(2, "<time_to_eat> <time_to_sleep> [optional: ", 41);
	write(2, "number_of_times_each_philosopher_must_eat]\n\n", 46);
	return (0);
}