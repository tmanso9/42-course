/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:52:19 by touteiro          #+#    #+#             */
/*   Updated: 2023/02/06 16:06:33 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

// t_table	*table(void)
// {
// 	static t_table	t;

// 	return (&t);
// }

int	dead(t_philo *philo)
{
	__uint64_t	moment;
	__uint64_t	diff;

	moment = get_time() - philo->start_time;
	if (moment <= philo->last_ate)
		return (0);
	diff = moment - philo->last_ate;
	if (diff > philo->vars.ttd)
	{
		printf("%lu %d died\n", moment, philo->i + 1);
		return (1);
	}
	return (0);
}

void	*check_life(void *data)
{
	t_philo	*philo;

	philo = data;
	while (!dead(philo))
		;
	exit(philo->pid);
}

static int	start_processes(t_table *table)
{
	int			i;
	__uint64_t	start;
	
	// gettimeofday(&start, NULL);
	// table.start_time = (start.tv_sec * (__uint64_t)1000) + \
	// 	(start.tv_usec / (__uint64_t)1000);
	start = get_time();
	table->dead = 0;
	i = 0;
	while(i < table->total)
	{
		table->philo[i].start_time = start;
		table->philo[i].vars.tte = table->tte;
		table->philo[i].vars.tts = table->tts;
		table->philo[i].vars.ttd = table->ttd;
		i++;
	}
	i = 0;
	while (i < table->total)
	{
		table->pid[i] = fork();
		if (table->pid[i] < 0)
			return (EXIT_FAILURE);
		if (table->pid[i] == 0)
		{
			table->philo[i].i = i;
			table->philo[i].pid = table->pid[i];
			if (pthread_create(&table->philo[i].check_life, NULL, check_life, &table->philo[i]))
				return (EXIT_FAILURE);
			while (1)
			{
				sem_wait(table->forks);
				printf("%lu %d has taken a fork\n", get_time() - table->philo[i].start_time, i + 1);
				sem_wait(table->forks);
				printf("%lu %d has taken a fork\n", get_time() - table->philo[i].start_time, i + 1);
				printf("%lu %d is eating\n", get_time() - table->philo[i].start_time, i + 1);
				table->philo[i].last_ate = get_time() - table->philo[i].start_time;
				my_usleep(table->tte);
				sem_post(table->forks);
				sem_post(table->forks);
				printf("%lu %d is sleeping\n", get_time() - table->philo[i].start_time, i + 1);
				my_usleep(table->tts);
				printf("%lu %d is thinking\n", get_time() - table->philo[i].start_time, i + 1);
			}
			break ;
		}
		table->i++;
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
		table.pid = ft_calloc(sizeof(pid_t), table.total);
		if (start_processes(&table) == EXIT_FAILURE/*  || \
			end_check() == EXIT_FAILURE */)
		{
			sem_close(table.forks);
			sem_unlink("/forks");
			free_all(&table);
			return (EXIT_FAILURE);
		}
		int status;
		waitpid(-1, &status, 0);
		int	i = 0;
		while (i < table.total)
		{
			if (status != table.pid[i])
				kill(table.pid[i], SIGKILL);
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
