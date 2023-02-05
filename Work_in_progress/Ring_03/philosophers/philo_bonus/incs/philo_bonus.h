/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:05:46 by touteiro          #+#    #+#             */
/*   Updated: 2023/02/05 13:13:22 by touteiro         ###   ########.fr       */
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

typedef struct s_philo
{
	int				pid;
	__uint64_t		last_eaten;
	int				times_eaten;
	int				full_belly;
}	t_philo;

typedef struct s_table
{
	t_philo			*philo;
	sem_t			*forks;
	int				total;
	__uint64_t		start_time;
	__uint64_t		ttd;
	__uint64_t		tte;
	__uint64_t		tts;
	int				min_times;
	int				unlimited;
	int				dead;
	int				all_full;
	int				i;
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
int			check_starvation(void);
int			dead(void);
int			all_eaten(void);
int			full(void);
//Time utils
__uint64_t	get_time(t_table table);
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