/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:52:19 by touteiro          #+#    #+#             */
/*   Updated: 2023/01/20 20:40:06 by touteiro         ###   ########.fr       */
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
	pthread_t	t1;
	pthread_t	t2;
	pthread_mutex_t	mutex;


	(void)argc;
	(void)argv;
	pthread_mutex_init(&mutex, NULL);
	if (pthread_create(&t1, NULL, &example, &mutex))
		return (EXIT_FAILURE);
	if (pthread_create(&t2, NULL, &example, &mutex))
		return (EXIT_FAILURE);
	if (pthread_join(t1, NULL))
		return (EXIT_FAILURE);
	if (pthread_join(t2, NULL))
		return (EXIT_FAILURE);
	pthread_mutex_destroy(&mutex);
	printf("Number of mails: %d\n", mails);
	return (EXIT_SUCCESS);
}
