/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:49:10 by touteiro          #+#    #+#             */
/*   Updated: 2023/01/25 22:02:52 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	give_forks(int i)
{
	if (i % 2 == 0)
	{
		table()->philo[i].left = &table()->forks[i % table()->total];
		if (table()->total > 1)
			table()->philo[i].right = &table()->forks[(i + 1) % table()->total];
	}
	else
	{
		table()->philo[i].left = &table()->forks[(i + 1) % table()->total];
		if (table()->total > 1)
			table()->philo[i].right = &table()->forks[i % table()->total];
	}
}


