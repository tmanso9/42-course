/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:52:19 by touteiro          #+#    #+#             */
/*   Updated: 2023/02/02 20:48:21 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_table	*table(void)
{
	static t_table	t;

	return (&t);
}

void	detach(void)
{
	int	i;

	i = -1;
	while (++i < table()->total)
	{
		pthread_detach(table()->philo[i].philo);
	}
}

void	*run(void *data)
{
	t_philo		*philo;
	// __uint64_t	ms;

	philo = data;
	// if (philo->index % 2)
	// 	my_usleep(60);
	
	// printf("index %d %p %p\n", philo->index, \
		// philo->first_fork, philo->second_fork);
	while (1)
	{
		if (table()->total == 1)
		{
			print_message(philo, FORK, get_time());
			my_usleep(table()->ttd);
			return (NULL);
		}
		/* if /(all_eaten())
		{
			// ms = get_time();
			// printf("all ate at %llu seen from %d!\n", ms, philo->index + 1);
			return (NULL);
		} */
		if (/* !all_eaten() &&  */pickup_forks(philo))
		{
			eat(philo);
			/*if (!all_eaten())*/
				do_sleep(philo);
		}
	}
	return (NULL);
}

int	check_starvation(void)
{
	int			i;
	__uint64_t	moment;
	__uint64_t	diff;

	// i = -1;
	// while (++i < table()->total)
	// {
	// 	moment = get_time();
	// 	pthread_mutex_lock(table()->status);
	// 	if (moment > table()->ttd && !table()->philo[i].times_eaten)
	// 	{
	// 		table()->dead = 1;
	// 		pthread_mutex_unlock(table()->status);
	// 		return (print_message(&table()->philo[i], DIE, moment));
	// 	}
	// 	pthread_mutex_unlock(table()->status);
	// }
	i = 0;
	moment = get_time();
	while (i < table()->total)
	{
		pthread_mutex_lock(table()->philo[i].eating);
		if (moment < table()->philo[i].last_eaten)
		{
			pthread_mutex_unlock(table()->philo[i].eating);
			i++;
			continue ;
		}
		diff = moment - table()->philo[i].last_eaten;
		if (diff >= (table()->ttd))
		{
			table()->dead = 1;
			pthread_mutex_unlock(table()->philo[i].eating);
			return (print_message(&table()->philo[i], DIE, moment));
		}
		pthread_mutex_unlock(table()->philo[i].eating);
		i++;
	}
	return (0);
}

int	main(int argc, char**argv)
{
	int			i;
	t_time		start;

	if (argc > 4 && argc < 7)
	{
		if (parse_args(argv, table()) == EXIT_FAILURE)
		{
			free_all(table());
			return (EXIT_FAILURE);
		}
		gettimeofday(&start, NULL);
		table()->start_time = (start.tv_sec * (__uint64_t)1000) + \
			(start.tv_usec / (__uint64_t)1000);
		table()->dead = 0;
		i = 0;
		while (i < table()->total)
		{
			table()->philo[i].last_eaten = get_time();
			if (pthread_create(&(table()->philo[i].philo), NULL, run, \
				&table()->philo[i]))
			{
				printf("hereeeee\n");
				return (EXIT_FAILURE);
			}
			usleep(1000000);
			i++;
		}
		while (1)
		{
			/* if (check_starvation())
			{
				// printf("all ate BIG\n");
				detach();
				break ;
			} */
		}
		i = 0;
		while (i < table()->total)
		{
			pthread_join(table()->philo[i].philo, NULL);
			i++;
		}
		while (i < table()->total)
		{
			pthread_mutex_destroy(&table()->forks[i]);
			pthread_mutex_destroy(table()->philo[i].eating);
			i++;
		}
		pthread_mutex_destroy(table()->status);
		free_all(table());
		return (EXIT_SUCCESS);
	}
	else
	{
		write(2, "\nInvalid number of arguments\n", 29);
		print_usage();
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
