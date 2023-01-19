/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_stack_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:32:07 by touteiro          #+#    #+#             */
/*   Updated: 2023/01/19 03:30:25 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	size_two_b(t_stack *total)
{
	if (total->curr_b_size == 1)
		return ;
	if (*total->b[total->a_size - total->curr_b_size] > \
		*total->b[total->a_size - total->curr_b_size + 1])
		return ;
	swap(total->b[total->a_size - total->curr_b_size], \
		total->b[total->a_size - total->curr_b_size + 1], total);
	update_arr(total, SB);
}
