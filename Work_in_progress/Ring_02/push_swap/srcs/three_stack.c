/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:14:06 by touteiro          #+#    #+#             */
/*   Updated: 2023/01/19 03:30:06 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	first_bigger(t_stack *total)
{
	if (total->curr_a_size > 3)
	{
		swap(total->a[0], total->a[1], total);
		update_arr(total, SA);
		size_three_a(total);
	}
	else
	{	
		rot(total, 'a', total->a, total->curr_a_size);
		update_arr(total, RA);
		size_three_a(total);
	}
}

static void	first_smaller(t_stack *total)
{
	if (total->curr_a_size > 3)
	{
		rot(total, 'a', total->a, total->curr_a_size);
		update_arr(total, RA);
		rot(total, 'a', total->a, total->curr_a_size);
		update_arr(total, RA);
		pb(total);
		rev_rot(total, 'a', total->a, total->curr_a_size);
		update_arr(total, RRA);
		rev_rot(total, 'a', total->a, total->curr_a_size);
		update_arr(total, RRA);
		pb(total);
		size_three_a(total);
	}
	else
	{
		rev_rot(total, 'a', total->a, total->curr_a_size);
		update_arr(total, RRA);
		size_three_a(total);
	}
}

void	size_three_a(t_stack *total)
{
	if (*total->a[0] < *total->a[1] && \
		*total->a[1] < *total->a[2])
		return ;
	if (*total->a[0] > *total->a[1] && \
		*total->a[0] < *total->a[2])
	{
		swap(total->a[0], total->a[1], total);
		update_arr(total, SA);
		size_three_a(total);
	}
	else if (*total->a[0] < *total->a[1])
		first_smaller(total);
	else if (*total->a[0] > *total->a[1])
		first_bigger(total);
}
