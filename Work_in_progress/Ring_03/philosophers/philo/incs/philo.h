/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:05:46 by touteiro          #+#    #+#             */
/*   Updated: 2023/01/23 19:17:25 by touteiro         ###   ########.fr       */
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

typedef struct s_philo
{
	pthread_t		philo;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	int				index;
}	t_philo;

typedef struct s_table
{
	t_philo			*philo;
	pthread_mutex_t	*forks;
	int				total;
	int				ttd;
	int				tte;
	int				tts;
	int				min_times;
	struct timeval	start_time;
}	t_table;

typedef struct timeval	t_time;

t_table	*table(void);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
void	*ft_calloc(size_t count, size_t size);
int		parse_args(char **argv, t_table *table);
void	free_all(t_table *table);
void	my_usleep(int milisec);

#endif