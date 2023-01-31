/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:49:10 by touteiro          #+#    #+#             */
/*   Updated: 2023/01/31 16:47:29 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	do_sleep(t_philo *philo)
{
	__uint64_t	ms;

	ms = get_time();
	if (!dead() && !all_eaten())
	{
		if (!dead() && !all_eaten())
			print_message(philo, SLEEP, ms);
		if (!dead() && !all_eaten())
		{
			my_usleep(table()->tts);
			return (1);
		}
	}
	return (0);
}

void	eat(t_philo *philo)
{
	__uint64_t	ms;

	ms = get_time();
	if (!dead() && !all_eaten())
	{
		print_message(philo, EAT, ms);
		pthread_mutex_lock(table()->status);
		philo->last_eaten = ms;
		philo->times_eaten++;
		pthread_mutex_unlock(table()->status);
	}
	if (!dead() && !all_eaten())
		my_usleep(table()->tte);
}

int	putdown_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->first_fork);
	if (!table()->forks_avail[philo->first_index] && !dead() && !all_eaten())
	{
		table()->forks_avail[philo->first_index] = 1;
		pthread_mutex_unlock(philo->first_fork);
	}
	else
	{
		pthread_mutex_unlock(philo->first_fork);
	}
	pthread_mutex_lock(philo->second_fork);
	if (!table()->forks_avail[philo->second_index] && !dead() && !all_eaten())
	{
		table()->forks_avail[philo->second_index] = 1;
		pthread_mutex_unlock(philo->second_fork);
	}
	else
	{
		pthread_mutex_unlock(philo->second_fork);
		return (0);
	}
	return (1);
}

int	pickup_forks(t_philo *philo)
{
	__uint64_t	ms;

	ms = get_time();
	pthread_mutex_lock(philo->first_fork);
	if (table()->forks_avail[philo->first_index] && !dead() && !all_eaten())
	{
		table()->forks_avail[philo->first_index] = 0;
		pthread_mutex_unlock(philo->first_fork);
		pthread_mutex_lock(philo->second_fork);
		if (table()->forks_avail[philo->second_index])
		{
			if (!dead() && !all_eaten())
				print_message(philo, FORK, ms);
			ms = get_time();
			table()->forks_avail[philo->second_index] = 0;
			pthread_mutex_unlock(philo->second_fork);
			if (!dead() && !all_eaten())
				print_message(philo, FORK, ms);
			return (1);
		}
		else
		{
			pthread_mutex_unlock(philo->second_fork);
			pthread_mutex_lock(philo->first_fork);
			table()->forks_avail[philo->first_index] = 1;
			pthread_mutex_unlock(philo->first_fork);
		}
	}
	else
	{
		pthread_mutex_unlock(philo->first_fork);
	}
	return (0);
}

void	give_forks(int i)
{
	// if (i % 2 == 0)
	// {
		table()->philo[i].first_fork = &table()->forks[i % table()->total];
		table()->philo[i].first_index = i % table()->total;
		table()->philo[i].second_index = (i + 1) % table()->total;
		if (table()->total > 1)
			table()->philo[i].second_fork = \
				&table()->forks[(i + 1) % table()->total];
		// printf("philo %d first i %d second %d first fork %p second fork %p\n", \
		// 	table()->philo[i].index + 1, table()->philo[i].first_index, \
		// 	table()->philo[i].second_index, table()->philo[i].first_fork, \
		// 	table()->philo[i].second_fork);
	// }
	// else
	// {
	// 	table()->philo[i].first_fork = \
	// 		&table()->forks[(i + 1) % table()->total];
	// 	table()->philo[i].first_index = (i + 1) % table()->total;
	// 	table()->philo[i].second_index = i % table()->total;
	// 	if (table()->total > 1)
	// 		table()->philo[i].second_fork = &table()->forks[i % table()->total];
	// 	printf("philo %d first i %d second %d first fork %p second fork %p\n", \
	// 		table()->philo[i].index + 1, table()->philo[i].first_index, \
	// 		table()->philo[i].second_index, table()->philo[i].first_fork, \
	// 		table()->philo[i].second_fork);
	// }
}
