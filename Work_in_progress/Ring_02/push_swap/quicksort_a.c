/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:26:12 by touteiro          #+#    #+#             */
/*   Updated: 2022/12/23 19:36:39 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate_if_needed(t_stack *total)
{
	while (total->rev)
	{
		rev_rot(total, 'a', total->a, total->curr_a_size);
		update_arr(total, 7);
		total->rev--;
	}
}

static void	rotate_while_searching(t_stack *total, int to_rotate)
{
	rot(total, 'a', total->a, total->curr_a_size);
	update_arr(total, 5);
	if (to_rotate)
		total->rev++;
}

int	send_to_b(t_stack *total, int len, int to_rotate, int count)
{
	int	i;

	i = -1;
	while (++i < len)
	{
		if (is_sorted(total))
			break ;
		if (*total->a[0] < total->a_median)
		{
			pb(total);
			count++;
		}
		else
			rotate_while_searching(total, to_rotate);
	}
	return (count);
}

void	quicksort_a(t_stack *total, int len)
{
	int	count;
	int	to_rotate;

	count = 0;
	if (is_sorted(total))
		return ;
	if (len < 11 || total->curr_a_size < 15)
	{
		if (len == 2)
			size_two_a(total);
		else
			size_five_a(total);
		return ;
	}
	if (len < total->curr_a_size)
		to_rotate = 1;
	else
		to_rotate = 0;
	total->a_median = find_median(total->a, len);
	count = send_to_b(total, len, to_rotate, count);
	rev_rotate_if_needed(total);
	quicksort_a(total, len - count);
	quicksort_b(total, count);
}
