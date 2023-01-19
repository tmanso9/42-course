/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_stack_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:32:34 by touteiro          #+#    #+#             */
/*   Updated: 2023/01/19 03:26:48 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	size_three_b(t_stack *total)
{
	if (*total->b[total->a_size - 3] > *total->b[total->a_size - 2] && \
		*total->b[total->a_size - 2] > *total->b[total->a_size - 1])
		return ;
	if (*total->b[total->a_size - 3] < *total->b[total->a_size - 2] && \
		*total->b[total->a_size - 3] > *total->b[total->a_size - 1])
	{
		swap(total->b[total->a_size - 3], total->b[total->a_size - 2], total);
		update_arr(total, SB);
		size_three_b(total);
	}
	else if (*total->b[total->a_size - 3] > *total->b[total->a_size - 2])
	{
		rev_rot(total, 'b', total->b, total->curr_b_size);
		update_arr(total, RRB);
		size_three_b(total);
	}
	else if (*total->b[total->a_size - 3] < \
		*total->b[total->a_size - 2])
	{
		rot(total, 'b', total->b, total->curr_b_size);
		update_arr(total, RB);
		size_three_b(total);
	}
}
