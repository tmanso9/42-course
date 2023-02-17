/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:49:10 by touteiro          #+#    #+#             */
/*   Updated: 2023/02/10 15:08:14 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	do_sleep(t_philo *philo)
{
	__uint64_t	ms;

	ms = get_time();
	if (!dead() && !full())
		print_message(philo, SLEEP, ms);
	my_usleep(table()->tts);
}

void	eat(t_philo *philo)
{
	__uint64_t	ms;

	ms = get_time();
	pthread_mutex_lock(&philo->eating);
	philo->last_eaten = ms;
	pthread_mutex_unlock(&philo->eating);
	if (!dead() && !full())
		print_message(philo, EAT, ms);
	philo->times_eaten++;
	if (!table()->unlimited && philo->times_eaten == table()->min_times)
	{
		pthread_mutex_lock(&philo->check_full);
		philo->full_belly = 1;
		pthread_mutex_unlock(&philo->check_full);
	}
	my_usleep(table()->tte);
	pthread_mutex_unlock(philo->first_fork);
	pthread_mutex_unlock(philo->second_fork);
}

int	pickup_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->first_fork);
	if (!dead() && !full())
		print_message(philo, FORK, get_time());
	if (philo->second_fork)
		pthread_mutex_lock(philo->second_fork);
	else
	{
		pthread_mutex_unlock(philo->first_fork);
		my_usleep(table()->ttd);
		return (0);
	}
	if (!dead() && !full())
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
