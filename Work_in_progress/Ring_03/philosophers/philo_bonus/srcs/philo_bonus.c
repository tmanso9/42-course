/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:52:19 by touteiro          #+#    #+#             */
/*   Updated: 2023/02/05 15:32:25 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

// t_table	*table(void)
// {
// 	static t_table	t;

// 	return (&t);
// }

static int	start_processes(t_table table)
{
	int			i;
	t_time		start;
	pid_t		*pid;

	gettimeofday(&start, NULL);
	table.start_time = (start.tv_sec * (__uint64_t)1000) + \
		(start.tv_usec / (__uint64_t)1000);
	table.dead = 0;
	pid = ft_calloc(sizeof(pid_t), table.total);
	i = 0;
	while (i < table.total)
	{
		pid[i] = fork();
		if (pid[i] < 0)
			return (EXIT_FAILURE);
		if (pid[i] == 0)
		{
			while (1)
			{
				pthread_create();
				sem_wait(table.forks);
				printf("%lu %d has taken a fork\n", get_time(table), i + 1);
				sem_wait(table.forks);
				printf("%lu %d has taken a fork\n", get_time(table), i + 1);
				printf("%lu %d is eating\n", get_time(table), i + 1);
				my_usleep(table.tte);
				sem_post(table.forks);
				sem_post(table.forks);
				printf("%lu %d is sleeping\n", get_time(table), i + 1);
				my_usleep(table.tts);
				printf("%lu %d is thinking\n", get_time(table), i + 1);
			}
			break ;
		}
		table.i++;
		i++;
	}
	return (EXIT_SUCCESS);
}

/* static int	end_check(void)
{
	int	i;

	while (1)
	{
		if (check_starvation() || all_eaten())
		{
			i = 0;
			while (i < table.total)
			{
				i++;
			}
			break ;
		}
	}
	return (EXIT_SUCCESS);
} */

int	main(int argc, char**argv)
{
	t_table		table;

	if (argc == 5 || argc == 6)
	{
		if (parse_args(argv, &table) == EXIT_FAILURE)
		{
			free_all(&table);
			return (EXIT_FAILURE);
		}
		if (start_processes(table) == EXIT_FAILURE/*  || \
			end_check() == EXIT_FAILURE */)
		{
			sem_close(table.forks);
			sem_unlink("/forks");
			free_all(&table);
			return (EXIT_FAILURE);
		}
		int i = 0;
		while (i < table.total)
		{
			waitpid(-1, NULL, 0);
			i++;
		}
		sem_close(table.forks);
		sem_unlink("/forks");
		free_all(&table);
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
