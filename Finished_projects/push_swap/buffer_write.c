/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_write.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:45:07 by touteiro          #+#    #+#             */
/*   Updated: 2022/12/14 14:04:52 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	write_rev_rotate(t_stack *total, int i)
{
	if (total->res_arr[i] == 7)
	{
		i++;
		if (total->res_arr[i] && total->res_arr[i] == 8)
		{
			write(1, "rrr\n", 4);
			i++;
		}
		else
			write(1, "rra\n", 4);
	}
	else if (total->res_arr[i] == 8)
	{
		i++;
		if (total->res_arr[i] && total->res_arr[i] == 7)
		{
			write(1, "rrr\n", 4);
			i++;
		}
		else
			write(1, "rrb\n", 4);
	}
	return (i);
}

static int	write_rotate(t_stack *total, int i)
{
	if (total->res_arr[i] == 5)
	{
		i++;
		if (total->res_arr[i] && total->res_arr[i] == 6)
		{
			write(1, "rr\n", 3);
			i++;
		}
		else
			write(1, "ra\n", 3);
	}
	else if (total->res_arr[i] == 6)
	{
		i++;
		if (total->res_arr[i] && total->res_arr[i] == 5)
		{
			write(1, "rr\n", 3);
			i++;
		}
		else
			write(1, "rb\n", 3);
	}
	return (i);
}

static int	write_push(t_stack *total, int i)
{
	if (total->res_arr[i] == 3)
	{
		write(1, "pa\n", 3);
		i++;
	}
	else if (total->res_arr[i] == 4)
	{
		write(1, "pb\n", 3);
		i++;
	}
	return (i);
}

static int	write_swap(t_stack *total, int i)
{
	if (total->res_arr[i] == 1)
	{
		i++;
		if (total->res_arr[i] && total->res_arr[i] == 2)
		{
			write(1, "ss\n", 3);
			i++;
		}
		else
			write(1, "sa\n", 3);
	}
	else if (total->res_arr[i] == 2)
	{
		i++;
		if (total->res_arr[i] && total->res_arr[i] == 1)
		{
			write(1, "ss\n", 3);
			i++;
		}
		else
			write(1, "sb\n", 3);
	}
	return (i);
}

/*
CODE
1:	sa
2:	sb
3:	pa
4:	pb
5:	ra
6:	rb
7:	rra
8:	rrb
*/
void	write_output(t_stack *total)
{
	int	i;

	i = 0;
	while (total->res_arr[i])
	{
		i = write_swap(total, i);
		i = write_push(total, i);
		i = write_rotate(total, i);
		i = write_rev_rotate(total, i);
	}
}
