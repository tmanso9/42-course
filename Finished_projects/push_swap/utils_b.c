/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 21:59:21 by touteiro          #+#    #+#             */
/*   Updated: 2022/12/14 14:06:02 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	advance_vars(t_stack *total, int *i, int *j)
{
	(*i)++;
	*j = total->a_size - total->curr_b_size - 1;
}

int	find_b_median(t_stack *total, int len)
{
	int	i;
	int	j;
	int	lower;
	int	higher;
	int	count;

	i = total->a_size - total->curr_b_size;
	j = i - 1;
	count = -1;
	while (++count < len - 1)
	{
		lower = 0;
		higher = 0;
		while (++j < total->a_size - total->curr_b_size + len)
		{
			if (*total->b[i] > *total->b[j])
				lower++;
			if (*total->b[i] < *total->b[j])
				higher++;
		}
		if (higher == len / 2)
			return (*total->b[i]);
		advance_vars(total, &i, &j);
	}
	return (*total->b[i]);
}
