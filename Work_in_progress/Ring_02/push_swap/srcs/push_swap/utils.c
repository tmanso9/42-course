/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:30:13 by touteiro          #+#    #+#             */
/*   Updated: 2022/11/22 18:16:27 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

int	is_sorted(t_stack *total)
{
	int	i;

	i = 0;
	while ((i + 1) < total->curr_a_size)
	{
		if (*total->a[i] > *total->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	smallest(int **arr, int stack_size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < stack_size)
	{
		while (j < stack_size && *arr[i] <= *arr[j])
			j++;
		if (j == stack_size)
			return (i);
		i++;
		j = 0;
	}
	return (i);
}

int	**transform_index(int **arr, int stack_size)
{
	int	i;
	int	j;
	int	**index_arr;

	i = -1;
	index_arr = ft_calloc(stack_size, sizeof(int *));
	while (++i < stack_size)
		index_arr[i] = ft_calloc(1, sizeof(int));
	i = 0;
}
