/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:49:10 by touteiro          #+#    #+#             */
/*   Updated: 2023/01/30 21:27:51 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	do_sleep(t_philo *philo)
{
	__uint64_t	ms;

	ms = get_time();
	if (!dead() && !all_eaten())
	{
		pthread_mutex_lock(table()->status);
		table()->forks_avail[philo->first_index] = 1;
		table()->forks_avail[philo->second_index] = 1;
		pthread_mutex_unlock(table()->status);
		print_message(philo, SLEEP, ms);
		my_usleep(table()->tts);
	}
}

void	eat(t_philo *philo)
{
	__uint64_t	ms;

	ms = get_time();
	if (!dead() && !all_eaten())
	{
		pthread_mutex_lock(table()->status);
		philo->last_eaten = ms;
		philo->times_eaten++;
		pthread_mutex_unlock(table()->status);
		print_message(philo, EAT, ms);
		my_usleep(table()->tte);
	}
	// pthread_mutex_unlock(philo->first_fork);
	// pthread_mutex_unlock(philo->second_fork);
}

int	pickup_forks(t_philo *philo)
{
	__uint64_t	ms;

	while (!dead() && !all_eaten() && philo->forks_taken != 2)
	{
		pthread_mutex_lock(philo->first_fork);
		pthread_mutex_lock(table()->status);
		if (table()->forks_avail[philo->first_index])
		{
			table()->forks_avail[philo->first_index] = 0;
			pthread_mutex_unlock(table()->status);
			pthread_mutex_unlock(philo->first_fork);
			philo->forks_taken++;
			ms = get_time();
			if (table()->total == 1)
			{
				print_message(philo, FORK, ms);
				my_usleep(table()->ttd);
				return (0);
			}
			pthread_mutex_lock(philo->second_fork);
			pthread_mutex_lock(table()->status);
			if (table()->forks_avail[philo->second_index])
			{
				table()->forks_avail[philo->second_index] = 0;
				pthread_mutex_unlock(table()->status);
				pthread_mutex_unlock(philo->second_fork);
				philo->forks_taken++;
			}
			else
			{
				philo->forks_taken--;
				table()->forks_avail[philo->first_index] = 1;
				pthread_mutex_unlock(table()->status);
				pthread_mutex_unlock(philo->second_fork);
			}
		}
		else
		{
			pthread_mutex_unlock(philo->first_fork);
			pthread_mutex_unlock(table()->status);
		}
	}
	philo->forks_taken = 0;
	if (!dead() && !all_eaten())
	{
		print_message(philo, FORK, ms);
		print_message(philo, FORK, ms);
	}
	return (1);
}

void	give_forks(int i)
{
	if (i % 2 == 0)
	{
		table()->philo[i].first_fork = &table()->forks[i % table()->total];
		table()->philo[i].first_index = i % table()->total;
		table()->philo[i].second_index = (i + 1) % table()->total;
		if (table()->total > 1)
			table()->philo[i].second_fork = \
				&table()->forks[(i + 1) % table()->total];
	}
	else
	{
		table()->philo[i].first_fork = \
			&table()->forks[(i + 1) % table()->total];
		table()->philo[i].first_index = (i + 1) % table()->total;
		table()->philo[i].second_index = i % table()->total;
		if (table()->total > 1)
			table()->philo[i].second_fork = &table()->forks[i % table()->total];
	}
}
