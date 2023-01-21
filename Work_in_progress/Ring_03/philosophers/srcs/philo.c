/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:52:19 by touteiro          #+#    #+#             */
/*   Updated: 2023/01/21 02:00:31 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	mails = 0;

void	*example(void *mutex)
{
	int	i;

	i = 0;
	while (i++ < 1000000)
	{
		pthread_mutex_lock(mutex);
		mails++;
		pthread_mutex_unlock(mutex);
	}
	return (NULL);
}

int	main(int argc, char**argv)
{
	pthread_t		*th;
	pthread_mutex_t	mutex;
	int				i;

	(void)argc;
	(void)argv;
	th = malloc(sizeof(pthread_t) * 4);
	if (!th)
		return (EXIT_FAILURE);
	i = 0;
	pthread_mutex_init(&mutex, NULL);
	while (i < 4)
	{
		if (pthread_create(&th[i], NULL, &example, &mutex))
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
	pthread_mutex_destroy(&mutex);
	free(th);
	printf("Number of mails: %d\n", mails);
	return (EXIT_SUCCESS);
}
