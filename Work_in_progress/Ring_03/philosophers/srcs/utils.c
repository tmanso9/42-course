/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:17:11 by touteiro          #+#    #+#             */
/*   Updated: 2023/01/23 18:36:18 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (2048);
	else
		return (0);
}

void	my_usleep(int milisec)
{
	struct timeval	end;
	struct timeval	start;

	gettimeofday(&start, NULL);
	end.tv_sec = start.tv_sec + (milisec / 1000);
	milisec %= 1000;
	end.tv_usec = start.tv_usec + (milisec * 1000);
	if (end.tv_usec > 999999)
	{
		end.tv_sec += (end.tv_usec / 1000000);
		end.tv_usec %= 1000000;
	}
	while (1)
	{
		gettimeofday(&start, NULL);
		if (start.tv_sec == end.tv_sec && start.tv_usec == end.tv_usec)
			return ;
	}
}

void	free_all(t_table *table)
{
	if (table)
	{
		if (table->philo)
			free(table->philo);
		if (table->forks)
			free(table->forks);
		free(table);
	}
}
