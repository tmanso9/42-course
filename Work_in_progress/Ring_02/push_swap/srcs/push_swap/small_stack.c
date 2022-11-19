/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:10:29 by touteiro          #+#    #+#             */
/*   Updated: 2022/11/19 19:17:07 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

void	swap(int *a, int *b)
{
	int	*tmp;

	tmp = ft_calloc(1, sizeof(int *));
	*tmp = *a;
	*a = *b;
	*b = *tmp;
	free(tmp);
}

void	size_two(t_stack *total)
{
	if (*total->a[0] > *total->a[1])
	{
		swap(total->a[0], total->a[1]);
		write(1, "sa\n", 3);
	}
}