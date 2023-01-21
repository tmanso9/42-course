/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:52:19 by touteiro          #+#    #+#             */
/*   Updated: 2023/01/21 16:50:20 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

typedef struct s_arr
{
	int				mails;
	pthread_mutex_t	mutex;
}	t_arr;

void	*example(void *data)
{
	int		i;
	t_arr	*thread;

	thread = data;
	i = 0;
	while (i++ < 1000000)
	{
		pthread_mutex_lock(&(thread->mutex));
		(thread->mails)++;
		pthread_mutex_unlock(&(thread->mutex));
	}
	return (NULL);
}

int	main(int argc, char**argv)
{
	pthread_t		*th;
	t_arr			arr;
	int				i;

	arr.mails = 0;
	i = 0;

	(void)argc;
	(void)argv;
	th = malloc(sizeof(pthread_t) * 4);
	if (!th)
		return (EXIT_FAILURE);
	i = 0;
	pthread_mutex_init(&arr.mutex, NULL);
	while (i < 4)
	{
		if (pthread_create(&th[i], NULL, &example, &arr))
			return (EXIT_FAILURE);
		printf("Thread %d has started\n", i++);
	}
	i = 0;
	while (i < 4)
	{
		if (pthread_join(th[i], NULL))
			return (EXIT_FAILURE);
		printf("Thread %d has finished execution\n", i++);
	}
	pthread_mutex_destroy(&arr.mutex);
	free(th);
	printf("Number of mails: %d\n", arr.mails);
	return (EXIT_SUCCESS);
}
