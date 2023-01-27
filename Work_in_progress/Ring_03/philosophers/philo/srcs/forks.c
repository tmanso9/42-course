/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:49:10 by touteiro          #+#    #+#             */
/*   Updated: 2023/01/27 13:42:30 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	do_sleep(t_philo *philo)
{
	__uint64_t	ms;

	ms = get_time();
	if (!dead())
		print_message(philo, SLEEP, ms);
	if (!dead() && !all_eaten())
		my_usleep(table()->tts);
}

void	eat(t_philo *philo)
{
	__uint64_t	ms;

	ms = get_time();
	if (!dead())
	{
		pthread_mutex_lock(table()->status);
		philo->last_eaten = ms;
		philo->times_eaten++;
		pthread_mutex_unlock(table()->status);
		print_message(philo, EAT, ms);
	}
	if (!dead())
		my_usleep(table()->tte);
	pthread_mutex_unlock(philo->first_fork);
	pthread_mutex_unlock(philo->second_fork);
}

int	pickup_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->first_fork);
	if (!dead())
		print_message(philo, FORK, get_time());
	if (philo->second_fork)
		pthread_mutex_lock(philo->second_fork);
	else
	{
		pthread_mutex_unlock(philo->first_fork);
		my_usleep(table()->ttd);
		return (0);
	}
	if (!dead() && philo->second_fork)
		print_message(philo, FORK, get_time());
	return (1);
}

void	give_forks(int i)
{
	if (i % 2 == 0)
	{
		table()->philo[i].first_fork = &table()->forks[i % table()->total];
		if (table()->total > 1)
			table()->philo[i].second_fork = \
				&table()->forks[(i + 1) % table()->total];
	}
	else
	{
		table()->philo[i].first_fork = \
			&table()->forks[(i + 1) % table()->total];
		if (table()->total > 1)
			table()->philo[i].second_fork = &table()->forks[i % table()->total];
	}
}
