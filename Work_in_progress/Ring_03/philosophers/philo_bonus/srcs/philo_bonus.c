/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:52:19 by touteiro          #+#    #+#             */
/*   Updated: 2023/02/07 16:53:52 by touteiro         ###   ########.fr       */
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
		sem_wait(philo->alive);
		printf("%lu %d died\n", moment, philo->i + 1);
		sem_post(philo->died);
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
	// if (pthread_join(philo->check_life, NULL))
	// 	return (NULL);
	exit(philo->pid);
	return (NULL);
}

void	*check_belly(void *data)
{
	int		i;
	t_table	*table;

	i = 0;
	table = data;
	while (i < table->total)
	{
		sem_wait(table->full);
		i++;
	}
	i = 0;
	while (i < table->total)
	{
		kill(table->pid[i], SIGKILL);
		i++;
	}
	printf("here\n");
	return (NULL);
}

void	*dead_philo(void *data)
{
	t_table	*table;
	int		i;

	table = data;
	sem_wait(table->died);
	i = 0;
	while (i < table->total)
	{
		sem_post(table->full);
		i++;
	}
		// kill(table->pid[i], SIGKILL);
	return (NULL);
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
		table->philo.start_time = start;
		table->philo.vars.tte = table->tte;
		table->philo.vars.tts = table->tts;
		table->philo.vars.ttd = table->ttd;
		i++;
	}
	i = 0;
	while (i < table->total)
	{
		table->pid[i] = fork();
		table->philo.pid = table->pid[i];
		if (table->pid[i] < 0)
			return (EXIT_FAILURE);
		if (table->pid[i] == 0)
		{
			table->philo.i = i;
			table->philo.died = table->died;
			table->philo.alive = table->alive;
			if (pthread_create(&table->philo.check_life, NULL, check_life, &table->philo))
				return (EXIT_FAILURE);
			while (1)
			{
				if (i % 2 == 0)
					usleep(200);
				sem_wait(table->forks);
				printf("%lu %d %s\n", get_time() - table->philo.start_time, i + 1, FORK);
				sem_wait(table->forks);
				printf("%lu %d has taken a fork\n", get_time() - table->philo.start_time, i + 1);
				printf("%lu %d is eating\n", get_time() - table->philo.start_time, i + 1);
				table->philo.last_ate = get_time() - table->philo.start_time;
				table->philo.times_eaten++;
				if (!table->unlimited && table->philo.times_eaten == table->min_times)
					sem_post(table->full);
				my_usleep(table->tte);
				sem_post(table->forks);
				sem_post(table->forks);
				printf("%lu %d is sleeping\n", get_time() - table->philo.start_time, i + 1);
				my_usleep(table->tts);
				printf("%lu %d is thinking\n", get_time() - table->philo.start_time, i + 1);
			}
			if (pthread_join(table->philo.check_life, NULL))
				return (EXIT_FAILURE);
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
	// int			i;

	if (argc == 5 || argc == 6)
	{
		if (parse_args(argv, &table) == EXIT_FAILURE)
		{
			free_all(&table);
			return (EXIT_FAILURE);
		}
		table.pid = ft_calloc(sizeof(pid_t), table.total);
		if (pthread_create(&table.all_full, NULL, check_belly, &table))
			return (EXIT_FAILURE);
		if (pthread_create(&table.dead, NULL, dead_philo, &table))
			return (EXIT_FAILURE);
		if (start_processes(&table) == EXIT_FAILURE/*  || \
			end_check() == EXIT_FAILURE */)
		{
			sem_close(table.forks);
			sem_unlink("/forks");
			free_all(&table);
			return (EXIT_FAILURE);
		}
		// int status;
		pthread_join(table.all_full, NULL);
		pthread_join(table.dead, NULL);
			// return (EXIT_FAILURE);
		// waitpid(-1, &status, 0);
		// i = 0;
		// while (i < table.total)
		// {
			// printf("%d %d\n", status, table.pid[i]);
			// kill(table.pid[i], SIGKILL);
			// i++;
		// }
		sem_close(table.forks);
		sem_unlink("/forks");
		sem_close(table.full);
		sem_unlink("/full");
		sem_close(table.died);
		sem_unlink("/dead");
		sem_close(table.alive);
		sem_unlink("/alive");
		free(table.pid);
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
