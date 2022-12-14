/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:30:13 by touteiro          #+#    #+#             */
/*   Updated: 2022/12/14 14:06:07 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	b_is_sorted(t_stack *total)
{
	int	i;

	i = total->a_size - total->curr_b_size;
	while ((i + 1) < total->a_size)
	{
		if (*total->b[i] < *total->b[i + 1])
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

int	biggest(t_stack *total)
{
	int	i;
	int	j;

	i = total->a_size - total->curr_b_size;
	j = i;
	while (i < total->a_size - 1)
	{
		while (j < total->a_size && *total->b[i] >= *total->b[j])
			j++;
		if (j == total->a_size)
			return (i);
		i++;
		j = total->a_size - total->curr_b_size;
	}
	return (i);
}

int	find_median(int **arr, int len)
{
	int	i;
	int	j;
	int	lower;
	int	higher;

	i = -1;
	j = -1;
	lower = 0;
	higher = 0;
	while (++i < len - 1)
	{
		while (++j < len)
		{
			if (*arr[i] > *arr[j])
				lower++;
			if (*arr[i] < *arr[j])
				higher++;
		}
		if (higher == len / 2)
			return (*arr[i]);
		lower = 0;
		higher = 0;
		j = -1;
	}
	return (*arr[i]);
}
