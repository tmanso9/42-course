/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:49:10 by touteiro          #+#    #+#             */
/*   Updated: 2023/02/02 20:48:38 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	do_sleep(t_philo *philo)
{
	__uint64_t	ms;

	ms = get_time();
	/*if (!all_eaten())*/
	// {
	print_message(philo, SLEEP, ms);
	my_usleep(table()->tts);
	ms = get_time();
		/*if (!all_eaten())*/
	print_message(philo, THINK, ms);
	// }
	return (1);
}

void	eat(t_philo *philo)
{
	__uint64_t	ms;

	ms = get_time();
	/*if (!all_eaten())*/
	// {
	print_message(philo, EAT, ms);
	pthread_mutex_lock(philo->eating);
	philo->last_eaten = ms;
	philo->times_eaten++;
	pthread_mutex_unlock(philo->eating);
	// }
	my_usleep(table()->tte);
	/*if (!all_eaten())*/
	// {
	pthread_mutex_lock(philo->first_fork);
	table()->forks_avail[philo->first_index] = 1;
	pthread_mutex_unlock(philo->first_fork);
	pthread_mutex_lock(philo->second_fork);
	table()->forks_avail[philo->second_index] = 1;
	pthread_mutex_unlock(philo->second_fork);
	// }
}

int	pickup_forks(t_philo *philo)
{
	__uint64_t	ms;

	pthread_mutex_lock(philo->first_fork);
	if (!all_eaten() && table()->forks_avail[philo->first_index])
	{
		table()->forks_avail[philo->first_index] = 0;
		pthread_mutex_unlock(philo->first_fork);
		pthread_mutex_lock(philo->second_fork);
		if (table()->forks_avail[philo->second_index])
		{
			ms = get_time();
			/*if (!all_eaten())*/
			print_message(philo, FORK, ms);
			ms = get_time();
			table()->forks_avail[philo->second_index] = 0;
			pthread_mutex_unlock(philo->second_fork);
			/*if (!all_eaten())*/
			print_message(philo, FORK, ms);
			return (1);
		}
		else
		{
			pthread_mutex_unlock(philo->second_fork);
			pthread_mutex_lock(philo->first_fork);
			table()->forks_avail[philo->first_index] = 1;
			pthread_mutex_unlock(philo->first_fork);
			return (0);
		}
	}
	else
		pthread_mutex_unlock(philo->first_fork);
	return (0);
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
		// printf("index %d %p %p\n", table()->philo[i].index, \
			// table()->philo[i].first_fork, table()->philo[i].second_fork);
	}
	else
	{
		table()->philo[i].first_fork = \
			&table()->forks[(i + 1) % table()->total];
		table()->philo[i].first_index = (i + 1) % table()->total;
		table()->philo[i].second_index = i % table()->total;
		if (table()->total > 1)
			table()->philo[i].second_fork = &table()->forks[i % table()->total];
		// printf("index %d %p %p\n", table()->philo[i].index, \
			// table()->philo[i].first_fork, table()->philo[i].second_fork);
	}
}
