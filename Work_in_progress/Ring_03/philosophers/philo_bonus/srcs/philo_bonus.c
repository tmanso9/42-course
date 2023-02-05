/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:52:19 by touteiro          #+#    #+#             */
/*   Updated: 2023/02/05 12:20:28 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

t_table	*table(void)
{
	static t_table	t;

	return (&t);
}

static int	start_processes(void)
{
	int			i;
	t_time		start;
	pid_t		*pid;

	gettimeofday(&start, NULL);
	table()->start_time = (start.tv_sec * (__uint64_t)1000) + \
		(start.tv_usec / (__uint64_t)1000);
	table()->dead = 0;
	pid = ft_calloc(sizeof(pid_t), table()->total);
	i = 0;
	while (i < table()->total)
	{
		pid[i] = fork();
		if (pid[i] < 0)
			return (EXIT_FAILURE);
		if (pid[i] == 0)
		{
			sem_wait(table()->forks);
			printf("here, i %d\n", i);
			sem_post(table()->forks);
			
		}
		table()->i++;
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
			while (i < table()->total)
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
	if (argc == 5 || argc == 6)
	{
		if (parse_args(argv, table()) == EXIT_FAILURE)
		{
			free_all(table());
			return (EXIT_FAILURE);
		}
		if (start_processes() == EXIT_FAILURE/*  || \
			end_check() == EXIT_FAILURE */)
		{
			sem_close(table()->forks);
			sem_unlink("forks");
			free_all(table());
			return (EXIT_FAILURE);
		}
		int i = 0;
		while (i < table()->total)
		{
			waitpid(-1, NULL, 0);
			i++;
		}
		sem_close(table()->forks);
		sem_unlink("forks");
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
