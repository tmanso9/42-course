/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:05:46 by touteiro          #+#    #+#             */
/*   Updated: 2023/01/27 20:55:27 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>

# define FORK	0
# define EAT	1
# define SLEEP	2
# define THINK	3
# define DIE	4
# define NONE	5

typedef struct s_philo
{
	pthread_t		philo;
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;
	int				index;
	__uint64_t		last_eaten;
	int				times_eaten;
	int				thinking;
}	t_philo;

typedef struct s_table
{
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*status;
	int				total;
	__uint64_t		ttd;
	__uint64_t		tte;
	__uint64_t		tts;
	int				min_times;
	__uint64_t		start_time;
	int				dead;
}	t_table;

typedef struct timeval	t_time;

t_table		*table(void);
int			ft_atoi(const char *str);
int			ft_isdigit(int c);
void		*ft_calloc(size_t count, size_t size);
int			parse_args(char **argv, t_table *table);
void		give_forks(int i);
__uint64_t	get_time(void);
int			pickup_forks(t_philo *philo);
void		eat(t_philo *philo);
void		do_sleep(t_philo *philo);
int			dead(void);
int			all_eaten(void);
int			print_message(t_philo *philo, int status, __uint64_t time);
void		free_all(t_table *table);
void		my_usleep(int milisec);

#endif