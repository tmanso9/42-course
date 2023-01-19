/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 21:59:21 by touteiro          #+#    #+#             */
/*   Updated: 2023/01/19 03:32:19 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_b_median(t_stack *total, int len)
{
	int	i;
	int	j;
	int	higher;
	int	count;

	i = total->a_size - total->curr_b_size;
	j = i - 1;
	count = -1;
	while (++count < len - 1)
	{
		higher = 0;
		while (++j < total->a_size - total->curr_b_size + len)
		{
			if (*total->b[i] < *total->b[j])
				higher++;
		}
		if (higher == len / 2)
			return (*total->b[i]);
		i++;
		j = total->a_size - total->curr_b_size - 1;
	}
	return (*total->b[i]);
}
