/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:53:37 by touteiro          #+#    #+#             */
/*   Updated: 2022/12/14 14:05:27 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate_if_needed(int *rev, t_stack *total)
{
	while (*rev)
	{
		rev_rot(total, 'b', total->b, total->curr_b_size);
		update_arr(total, 8);
		(*rev)--;
	}
}

static int	send_to_a(t_stack *total, int *count, int *to_rotate, int *rev)
{
	if (*total->b[total->a_size - total->curr_b_size] >= total->b_median)
	{
		pa(total);
		(*count)++;
	}
	else
	{
		rot(total, 'b', total->b, total->curr_b_size);
		update_arr(total, 6);
		if (*to_rotate)
			(*rev)++;
	}
	return (1);
}

static int	b_sorted_check(t_stack *total)
{
	if (is_sorted(total) && b_is_sorted(total))
	{
		while (total->curr_b_size)
			pa(total);
		return (1);
	}
	if (total->curr_b_size <= 4)
	{
		if (total->curr_b_size == 2)
			size_two_b(total);
		else if (total->curr_b_size == 3)
			size_three_b(total);
		else if (total->curr_b_size == 4)
			size_four_b(total);
		while (total->curr_b_size)
			pa(total);
		return (1);
	}
	return (0);
}

static int	b_initial_check(t_stack *total, int len, int *to_rotate)
{
	if (!len)
		return (0);
	if (len == 1 && total->curr_b_size)
	{
		pa(total);
		return (0);
	}
	if (len < total->curr_b_size)
		*to_rotate = 1;
	else
		*to_rotate = 0;
	if (len == 2 && total->curr_b_size > 1)
	{
		size_two_b(total);
		pa(total);
		pa(total);
		return (0);
	}
	return (1);
}

void	quicksort_b(t_stack *total, int len)
{
	int	i;
	int	count;
	int	rev;
	int	to_rotate;

	i = 0;
	count = 0;
	rev = 0;
	to_rotate = 0;
	if (!b_initial_check(total, len, &to_rotate))
		return ;
	if (b_sorted_check(total))
		return ;
	total->b_median = find_b_median(total, len);
	while (i < len)
		i += send_to_a(total, &count, &to_rotate, &rev);
	rev_rotate_if_needed(&rev, total);
	if (count)
		quicksort_a(total, count);
	if (len)
		quicksort_b(total, len - count);
	if (!is_sorted(total))
		quicksort_a(total, count);
}
