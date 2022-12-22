/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:59:46 by touteiro          #+#    #+#             */
/*   Updated: 2022/12/14 14:05:31 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stacks(t_stack *total)
{
	total->a_size = 0;
	total->curr_b_size = 0;
	total->len = 0;
	total->index = 0;
	total->res_arr = 0;
	total->a = 0;
	total->b = 0;
	total->a_median = 0;
	total->b_median = 0;
	total->rev = 0;
}

void	free_stacks(t_stack *total)
{
	int	i;

	i = 0;
	while (i < total->a_size)
	{
		free(total->a[i]);
		i++;
	}
	if (total->a)
		free(total->a);
	if (total->curr_b_size > 0)
	{
		i = 0;
		while (i < total->curr_b_size)
		{
			free(total->b[i]);
			i++;
		}
	}
	if (total->b)
		free(total->b);
	if (total->res_arr)
		free(total->res_arr);
	free(total);
}

/*
CODE
1:	sa
2:	sb
3:	pa
4:	pb
5:	ra
6:	rb
7:	rra
8:	rrb
*/
void	update_arr(t_stack *total, char code)
{
	total->res_arr[total->index] = code;
	total->index++;
}
