/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:52:19 by touteiro          #+#    #+#             */
/*   Updated: 2023/02/03 17:16:19 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	start_threads(void)
{
	int			i;
	t_time		start;

	gettimeofday(&start, NULL);
	table()->start_time = (start.tv_sec * (__uint64_t)1000) + \
		(start.tv_usec / (__uint64_t)1000);
	table()->dead = 0;
	i = 0;
	while (i < table()->total)
	{
		if (pthread_create(&(table()->philo[i].philo), NULL, run, \
			&table()->philo[i]))
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

static int	end_check(void)
{
	int	i;

	while (1)
	{
		if (check_starvation() || all_eaten())
		{
			i = 0;
			while (i < table()->total)
			{
				if (pthread_join(table()->philo[i].philo, NULL))
					return (EXIT_FAILURE);
				i++;
			}
			break ;
		}
	}
	return (EXIT_SUCCESS);
}

int	main(int argc, char**argv)
{
	if (argc > 1 && argc < 7)
	{
		if (parse_args(argv, table()) == EXIT_FAILURE)
		{
			free_all(table());
			return (EXIT_FAILURE);
		}
		if (start_threads() == EXIT_FAILURE || \
			end_check() == EXIT_FAILURE)
		{
			mutexes_destroy();
			free_all(table());
			return (EXIT_FAILURE);
		}
		mutexes_destroy();
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
