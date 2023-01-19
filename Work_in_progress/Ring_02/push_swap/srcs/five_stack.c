/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:10:29 by touteiro          #+#    #+#             */
/*   Updated: 2023/01/19 03:23:43 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_and_repeat_a(t_stack *total, char code)
{
	if (code == 5)
	{
		rot(total, 'a', total->a, total->curr_a_size);
		update_arr(total, RA);
		size_five_a(total);
	}
	if (code == 7)
	{
		rev_rot(total, 'a', total->a, total->curr_a_size);
		update_arr(total, RRA);
		size_five_a(total);
	}
}

void	size_five_a(t_stack *total)
{
	if (is_sorted(total))
		return ;
	else if (smallest(total->a, total->curr_a_size) == 0 && \
		total->curr_a_size == 4)
	{
		pb(total);
		size_three_a(total);
		pa(total);
	}
	else if (smallest(total->a, total->curr_a_size) == 0 && \
		total->curr_a_size > 4)
	{
		pb(total);
		size_five_a(total);
		pa(total);
	}
	else if (smallest(total->a, total->curr_a_size) > 0 && \
		smallest(total->a, total->curr_a_size) < (total->curr_a_size / 2))
		rotate_and_repeat_a(total, 5);
	else if (smallest(total->a, total->curr_a_size) > 0 && \
		smallest(total->a, total->curr_a_size) >= (total->curr_a_size / 2))
		rotate_and_repeat_a(total, 7);
}
