/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:59:46 by touteiro          #+#    #+#             */
/*   Updated: 2022/12/24 01:26:59 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stacks(t_stack *total)
{
	total->a_size = 0;
	total->curr_b_size = 0;
	total->len = 0;
	total->index = 0;
	total->log = 0;
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
	while (i < total->curr_a_size)
	{
		free(total->a[i]);
		i++;
	}
	if (total->a)
		free(total->a);
	if (total->curr_b_size)
	{
		while (total->curr_b_size)
		{
			free(total->b[total->a_size - total->curr_b_size]);
			total->curr_b_size--;
		}
	}
	if (total->b)
		free(total->b);
	if (total->log)
		free(total->log);
	free(total);
}

void	free_nums(char **nums)
{
	int	i;

	i = -1;
	while (nums[++i])
		free(nums[i]);
	free(nums);
}

void	clean_exit(t_stack *total, char **nums)
{
	if (nums)
		free_nums(nums);
	free_stacks(total);
	exit(0);
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
	total->log[total->index] = code;
	total->index++;
}
