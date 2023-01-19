/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   four_stack_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:33:05 by touteiro          #+#    #+#             */
/*   Updated: 2023/01/19 03:24:28 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	size_four_b(t_stack *total)
{
	if (*total->b[total->a_size - 4] > *total->b[total->a_size - 3] && \
		*total->b[total->a_size - 3] > *total->b[total->a_size - 2] && \
		*total->b[total->a_size - 2] > *total->b[total->a_size - 1])
		return ;
	if (biggest(total) == total->a_size - 4)
	{
		pa(total);
		size_three_b(total);
		return ;
	}
	else if (biggest(total) > total->a_size - 4 && \
		biggest(total) < total->a_size - 2)
	{
		rot(total, 'b', total->b, total->curr_b_size);
		update_arr(total, RB);
		size_four_b(total);
	}
	else
	{
		rev_rot(total, 'b', total->b, total->curr_b_size);
		update_arr(total, RRB);
		size_four_b(total);
	}
}
