/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:48:02 by touteiro          #+#    #+#             */
/*   Updated: 2022/12/14 14:05:06 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *a, int *b)
{
	int	*tmp;

	tmp = ft_calloc(1, sizeof(int *));
	*tmp = *a;
	*a = *b;
	*b = *tmp;
	free(tmp);
}

void	pa(t_stack *total)
{
	total->a[total->curr_a_size] = (int *)malloc(sizeof(int));
	total->curr_a_size++;
	rev_rot(total, 'a', total->a, total->curr_a_size);
	*total->a[0] = *total->b[total->a_size - total->curr_b_size];
	free(total->b[total->a_size - total->curr_b_size]);
	total->curr_b_size--;
	update_arr(total, 3);
}

void	pb(t_stack *total)
{
	total->curr_b_size++;
	total->b[total->a_size - total->curr_b_size] = (int *)malloc(sizeof(int));
	*total->b[total->a_size - total->curr_b_size] = *total->a[0];
	rot(total, 'a', total->a, total->curr_a_size);
	total->curr_a_size--;
	free(total->a[total->curr_a_size]);
	update_arr(total, 4);
}

void	rot(t_stack *total, char id, int **stack, int size)
{
	int	i;
	int	tmp;

	if (id == 'a')
	{
		i = 0;
		tmp = *stack[0];
	}
	else
	{
		i = total->a_size - size;
		tmp = *stack[i];
		size = total->a_size;
	}
	while (i < size - 1)
	{
		*stack[i] = *stack[i + 1];
		i++;
	}
	*stack[i] = tmp;
}

void	rev_rot(t_stack *total, char id, int **stack, int size)
{
	int	i;
	int	tmp;

	if (id == 'a')
	{
		i = size - 1;
		tmp = *stack[size - 1];
		while (i > 0)
		{
			*stack[i] = *stack[i - 1];
			i--;
		}
		*stack[i] = tmp;
	}
	else
	{
		i = total->a_size - 1;
		tmp = *stack[i];
		while (i > total->a_size - total->curr_b_size)
		{
			*stack[i] = *stack[i - 1];
			i--;
		}
		*stack[i] = tmp;
	}
}
