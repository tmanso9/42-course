/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:05:46 by touteiro          #+#    #+#             */
/*   Updated: 2023/02/06 15:57:28 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <signal.h>
# include <pthread.h>
# include <sys/time.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <semaphore.h>
# include <sys/wait.h>
# include <semaphore.h>

# define FORK	0
# define EAT	1
# define SLEEP	2
# define THINK	3
# define DIE	4

typedef struct s_vars
{
	__uint64_t		ttd;
	__uint64_t		tte;
	__uint64_t		tts;	
}	t_vars;

typedef struct s_philo
{
	int				pid;
	int				i;
	__uint64_t		last_ate;
	int				times_eaten;
	int				full_belly;
	pthread_t		check_life;
	__uint64_t		start_time;
	t_vars			vars;
}	t_philo;

typedef struct s_table
{
	t_philo			*philo;
	sem_t			*forks;
	__uint64_t		ttd;
	__uint64_t		tte;
	__uint64_t		tts;
	int				total;
	int				min_times;
	int				unlimited;
	int				dead;
	int				all_full;
	int				i;
	pid_t			*pid;
}	t_table;

typedef struct timeval	t_time;

//Parsing
int			parse_args(char **argv, t_table *table);
int			args_valid(char **argv);
//Run threads
void		give_forks(int i);
int			run(int i);
int			pickup_forks(t_philo *philo);
void		eat(t_philo *philo);
void		do_sleep(t_philo *philo);
int			check_starvation(t_philo *philo);
int			dead(t_philo *philo);
int			all_eaten(void);
int			full(void);
//Time utils
__uint64_t	get_time(void);
void		my_usleep(int milisec);
//Utils
int			ft_atoi(const char *str);
int			ft_isdigit(int c);
void		*ft_calloc(size_t count, size_t size);
t_table		*table(void);
int			print_message(t_philo *philo, int status, __uint64_t time);
int			print_usage(void);
void		mutexes_destroy(void);
void		free_all(t_table *table);

#endif