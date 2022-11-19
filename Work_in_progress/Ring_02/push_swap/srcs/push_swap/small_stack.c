/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:10:29 by touteiro          #+#    #+#             */
/*   Updated: 2022/11/19 20:49:40 by touteiro         ###   ########.fr       */
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

void	rot(int **stack, int size)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = *stack[0];
	while (i < size - 1)
	{
		*stack[i] = *stack[i + 1];
		i++;
	}
	*stack[i] = tmp;
}

void	rev_rot(int **stack, int size)
{
	int	i;
	int	tmp;

	i = size - 1;
	tmp = *stack[size - 1];
	while (i > 0)
	{
		*stack[i] = *stack[i - 1];
		i--;
	}
	*stack[i] = tmp;
}

void	size_two(t_stack *total)
{
	if (*total->a[0] > *total->a[1])
	{
		swap(total->a[0], total->a[1]);
		write(1, "sa\n", 3);
	}
}

void	size_three(t_stack *total)
{	
	if (*total->a[0] < *total->a[1] && \
		*total->a[1] < *total->a[2])
		return ;
	if (*total->a[0] > *total->a[1] && \
		*total->a[0] < *total->a[2])
	{
		swap(total->a[0], total->a[1]);
		write(1, "sa\n", 3);
		size_three(total);
	}
	else if (*total->a[0] < *total->a[1])
	{
		rev_rot(total->a, total->a_size);
		write(1, "rra\n", 4);
		size_three(total);
	}
	else if (*total->a[0] > *total->a[1])
	{
		rot(total->a, total->a_size);
		write(1, "ra\n", 3);
		size_three(total);
	}
	/*
	
	se 3 1 2
	
	   init	ra
	   3	1
	   1	2
	   2	3
	
	se 3 2 1

	   init	sa	rra
	   3	2	1
	   2	3	2
	   1	1	3
	
	
	
	
	
	
	se 1 2 3 return
	
	se 1 3 2

	   init	rra	sa
	   1 	2	1
	   3	1	2
	   2	3	3
	
	se 2 1 3
	
	   init	sa
	   2	1
	   1	2
	   3	3
	
	se 2 3 1
	
	   init	rra
	   2	1
	   3	2
	   1	3
	*/
}