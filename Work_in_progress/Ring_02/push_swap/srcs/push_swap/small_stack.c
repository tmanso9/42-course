/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:10:29 by touteiro          #+#    #+#             */
/*   Updated: 2022/11/25 19:47:09 by touteiro         ###   ########.fr       */
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

void	rot(t_stack *total, char id, int **stack, int size)
{
	int	i;
	int	tmp;

	if (id == 'a')
	{
		i = 0;
		tmp = *stack[0];
	}
	else
	{
		i = total->a_size - size;
		tmp = *stack[i];
		size = total->a_size;
	}
	while (i < size - 1)
	{
		*stack[i] = *stack[i + 1];
		i++;
	}
	*stack[i] = tmp;
}
/*void	rot(t_stack *total, char id, int **stack, int size)
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
}*/

/*void	rev_rot(int **stack, int size)
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
}*/

void	rev_rot(t_stack *total, char id, int **stack, int size)
{
	int	i;
	int	tmp;

	if (id == 'a')
	{
		i = size - 1;
		tmp = *stack[size - 1];
		while (i > 0)
		{
			*stack[i] = *stack[i - 1];
			i--;
		}
		*stack[i] = tmp;
	}
	else
	{
		i = total->a_size - 1;
		tmp = *stack[i];
		while (i > total->a_size - total->curr_b_size)
		{
			*stack[i] = *stack[i - 1];
			i--;
		}
		*stack[i] = tmp;
	}
}

void	pa(t_stack *total)
{
	total->a[total->curr_a_size] = (int *)malloc(sizeof(int));
	total->curr_a_size++;
	rev_rot(total, 'a', total->a, total->curr_a_size);
	*total->a[0] = *total->b[total->a_size - total->curr_b_size];
	free(total->b[total->a_size - total->curr_b_size]);
	total->curr_b_size--;
}

void	pb(t_stack *total)
{
	total->curr_b_size++;
	total->b[total->a_size - total->curr_b_size] = (int *)malloc(sizeof(int));
	*total->b[total->a_size - total->curr_b_size] = *total->a[0];
	rot(total, 'a', total->a, total->curr_a_size);
	total->curr_a_size--;
	free(total->a[total->curr_a_size]);
}

void	size_two(t_stack *total)
{
	if (is_sorted(total))
		return ;
	swap(total->a[0], total->a[1]);
	write(1, "sa\n", 3);
}

void	size_three(t_stack *total)
{
	// printf("got here\nA:\n");
	// printf("%d\n", *total->a[0]);
	// printf("%d\n", *total->a[1]);
	// printf("%d\n", *total->a[2]);
	// printf("%d\n", *total->a[3]);
	// printf("B:\n");
	// printf("%d\n", *total->b[total->a_size - total->curr_b_size]);
	// return ;
	if (is_sorted(total))
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
		rev_rot(total, 'a', total->a, total->curr_a_size);
		write(1, "rra\n", 4);
		size_three(total);
	}
	else if (*total->a[0] > *total->a[1])
	{
		rot(total, 'a', total->a, total->curr_a_size);
		write(1, "ra\n", 3);
		size_three(total);
	}
}

void	size_four(t_stack *total)
{
	if (is_sorted(total))
		return ;
	if (smallest(total->a, total->curr_a_size) == 0)
	{
		pb(total);
		write(1, "pb\n", 3);
		size_three(total);
		pa(total);
		write(1, "pa\n", 3);
		return ;
	}
	else if (smallest(total->a, total->curr_a_size) > 0 && \
		smallest(total->a, total->curr_a_size) < (total->curr_a_size / 2))
	{
		rot(total, 'a', total->a, total->curr_a_size);
		write(1, "ra\n", 3);
		size_four(total);
	}
	else if (smallest(total->a, total->curr_a_size) > 0 && \
		smallest(total->a, total->curr_a_size) >= (total->curr_a_size / 2))
	{
		rev_rot(total, 'a', total->a, total->curr_a_size);
		write(1, "rra\n", 4);
		size_four(total);
	}
}

void	size_five(t_stack *total)
{
	// printf("got here\n");
	// printf("curr a size is %d\n", total->curr_a_size);
	// printf("smallest is %d\n", smallest(total->a, total->curr_a_size));
	if (is_sorted(total))
		return ;
	if (smallest(total->a, total->curr_a_size) == 0 && total->curr_a_size == 4)
	{
		pb(total);
		write(1, "pb\n", 3);
		size_three(total);
		pa(total);
		write(1, "pa\n", 3);
		return ;
	}
	if (smallest(total->a, total->curr_a_size) == 0 && total->curr_a_size > 4)
	{
		pb(total);
		write(1, "pb\n", 3);
		size_five(total);
		pa(total);
		write(1, "pa\n", 3);
	}
	else if (smallest(total->a, total->curr_a_size) > 0 && \
		smallest(total->a, total->curr_a_size) < (total->curr_a_size / 2))
	{
		rot(total, 'a', total->a, total->curr_a_size);
		write(1, "ra\n", 3);
		size_five(total);
	}
	else if (smallest(total->a, total->curr_a_size) > 0 && \
		smallest(total->a, total->curr_a_size) >= (total->curr_a_size / 2))	{
		rev_rot(total, 'a', total->a, total->curr_a_size);
		write(1, "rra\n", 4);
		size_five(total);
	}
}
