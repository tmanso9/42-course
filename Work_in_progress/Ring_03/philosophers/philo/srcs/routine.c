/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:55:56 by touteiro          #+#    #+#             */
/*   Updated: 2023/02/05 10:34:14 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*run(void *data)
{
	t_philo		*philo;

	philo = data;
	while (!dead() && !full())
	{
		if (philo->index % 2 == 0)
			usleep(200);
		if (!pickup_forks(philo))
			return (NULL);
		eat(philo);
		do_sleep(philo);
		if (!dead() && !full())
			print_message(philo, THINK, get_time());
	}
	return (NULL);
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

int	check_starvation(void)
{
	int			i;
	__uint64_t	moment;
	__uint64_t	diff;
	__uint64_t	last_ate;

	i = -1;
	moment = get_time();
	while (++i < table()->total)
	{
		pthread_mutex_lock(&table()->philo[i].eating);
		last_ate = table()->philo[i].last_eaten;
		pthread_mutex_unlock(&table()->philo[i].eating);
		if (moment <= last_ate)
			continue ;
		diff = moment - last_ate;
		if (diff >= (table()->ttd))
		{
			pthread_mutex_lock(table()->status);
			table()->dead = 1;
			pthread_mutex_unlock(table()->status);
			return (print_message(&table()->philo[i], DIE, moment));
		}
	}
	return (0);
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
