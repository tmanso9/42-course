/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_write.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:45:07 by touteiro          #+#    #+#             */
/*   Updated: 2022/12/22 20:54:08 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*static int	write_rev_rotate(t_stack *total, int i)
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
}*/

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
9:	ss
10:	rr
11:	rrr
*/
void	write_output(t_stack *total)
{
	int	i;
	int	j;
	int	changed;

	i = 0;
	changed = 1;
	while (changed)
	{
		changed = 0;
		// ft_printf("got in, i %d\n", i);
		if (!(total->res_arr[i]))
			i = 0;
		while (total->res_arr[i])
		{
			/* if (total->res_arr[i] == 7 && total->res_arr[i + 1] && total->res_arr[i + 1] == 4 && \
				(total->res_arr[i + 2] && total->res_arr[i + 2] == 5) && \
				(total->res_arr[i + 2] && total->res_arr[i + 2] == 3))
			{
				total->res_arr[i] = 7;
				total->res_arr[i + 1] = 1;
				total->res_arr[i + 2] = 5;
				j = i + 1;
				while (total->res_arr[j + 3])
				{
					total->res_arr[j] = total->res_arr[j + 3];
					j++;
				}
				total->res_arr[j] = 0;

				
				// write(1, "rrb\n", 4);
				// write(1, "sb\n", 3);
				i += 3;
				changed = 1;
			} 
			if (total->res_arr[i] == 6 && total->res_arr[i + 1] && total->res_arr[i + 1] == 3 && \
				(total->res_arr[i + 2] && total->res_arr[i + 2] == 8) && \
				(total->res_arr[i + 2] && total->res_arr[i + 2] == 4))
			{
				total->res_arr[i] = 2;
				j = i + 1;
				while (total->res_arr[j + 3])
				{
					total->res_arr[j] = total->res_arr[j + 3];
					j++;
				}
				total->res_arr[j] = 0;
				
				// write(1, "rrb\n", 4);
				// write(1, "sb\n", 3);
				i++;
				changed = 1;
			}*/
			if (total->res_arr[i] == 3 && total->res_arr[i + 1] && total->res_arr[i + 1] == 8 && \
				(total->res_arr[i + 2] && total->res_arr[i + 2] == 4))
			{
				total->res_arr[i] = 8;
				total->res_arr[i + 1] = 2;
				j = i + 2;
				while (total->res_arr[j + 1])
				{
					total->res_arr[j] = total->res_arr[j + 1];
					j++;
				}
				total->res_arr[j] = 0;
				// write(1, "rrb\n", 4);
				// write(1, "sb\n", 3);
				i += 2;
				changed = 1;
			}
			/*if (total->res_arr[i] == 5 && total->res_arr[i + 1] && total->res_arr[i + 1] == 4 && \
				(total->res_arr[i + 2] && total->res_arr[i + 2] == 7) && \
				(total->res_arr[i + 2] && total->res_arr[i + 2] == 3))
			{
				total->res_arr[i] = 1;
				j = i + 1;
				while (total->res_arr[j + 3])
				{
					total->res_arr[j] = total->res_arr[j + 3];
					j++;
				}
				total->res_arr[j] = 0;

				
				// write(1, "rrb\n", 4);
				// write(1, "sb\n", 3);
				i++;
				changed = 1;
			}*/
			if (total->res_arr[i] == 4 && total->res_arr[i + 1] && total->res_arr[i + 1] == 7 && \
				total->res_arr[i + 2] && total->res_arr[i + 2] == 3)
			{
				total->res_arr[i] = 7;
				total->res_arr[i + 1] = 1;
				j = i + 2;
				while (total->res_arr[j + 1])
				{
					total->res_arr[j] = total->res_arr[j + 1];
					j++;
				}
				total->res_arr[j] = 0;
				// write(1, "rra\n", 4);
				// write(1, "sa\n", 3);
				i += 2;
				changed = 1;
			}
			if ((total->res_arr[i] == 1 && total->res_arr[i + 1] && total->res_arr[i + 1] == 2) || \
				(total->res_arr[i] == 2 && total->res_arr[i + 1] && total->res_arr[i + 1] == 1))
			{
				total->res_arr[i] = 9;
				j = i + 1;
				while (total->res_arr[j + 1])
				{
					total->res_arr[j] = total->res_arr[j + 1];
					j++;
				}
				total->res_arr[j] = 0;
				i += 1;
				changed = 1;
				// write(1, "ss\n", 3);
			}
			if ((total->res_arr[i] == 5 && total->res_arr[i + 1] && total->res_arr[i + 1] == 6) || \
				(total->res_arr[i] == 6 && total->res_arr[i + 1] && total->res_arr[i + 1] == 5))
			{
				total->res_arr[i] = 10;
				j = i + 1;
				while (total->res_arr[j + 1])
				{
					total->res_arr[j] = total->res_arr[j + 1];
					j++;
				}
				total->res_arr[j] = 0;
				i += 1;
				changed = 1;
				// write(1, "rr\n", 3);
			}
			/*if ((total->res_arr[i] == 7 && total->res_arr[i + 1] && total->res_arr[i + 1] == 8) || \
				(total->res_arr[i] == 8 && total->res_arr[i + 1] && total->res_arr[i + 1] == 7))
			{
				total->res_arr[i] = 11;
				j = i + 1;
				while (total->res_arr[j + 1])
				{
					total->res_arr[j] = total->res_arr[j + 1];
					j++;
				}
				total->res_arr[j] = 0;
				i += 1;
				changed = 1;
				// write(1, "rrr\n", 4);
			}*/
			if ((total->res_arr[i] == 5 && total->res_arr[i + 1] && total->res_arr[i + 1] == 7) ||
				(total->res_arr[i] == 6 && total->res_arr[i + 1] && total->res_arr[i + 1] == 8) ||
				(total->res_arr[i] == 7 && total->res_arr[i + 1] && total->res_arr[i + 1] == 5) ||
				(total->res_arr[i] == 8 && total->res_arr[i + 1] && total->res_arr[i + 1] == 6) ||
				(total->res_arr[i] == 3 && total->res_arr[i + 1] && total->res_arr[i + 1] == 4) ||
				(total->res_arr[i] == 4 && total->res_arr[i + 1] && total->res_arr[i + 1] == 3) ||
				(total->res_arr[i] == 1 && total->res_arr[i + 1] && total->res_arr[i + 1] == 1) ||
				(total->res_arr[i] == 2 && total->res_arr[i + 1] && total->res_arr[i + 1] == 2) ||
				(total->res_arr[i] == 9 && total->res_arr[i + 1] && total->res_arr[i + 1] == 9) ||
				(total->res_arr[i] == 10 && total->res_arr[i + 1] && total->res_arr[i + 1] == 11) ||
				(total->res_arr[i] == 11 && total->res_arr[i + 1] && total->res_arr[i + 1] == 10))
			{
				j = i;
				while (total->res_arr[j + 2])
				{
					total->res_arr[j] = total->res_arr[j + 2];
					j++;
				}
				total->res_arr[j] = 0;
				i += 1;
				changed = 1;
			}
			if (total->res_arr[i] == 5 && total->res_arr[i + 1] && total->res_arr[i + 1] == 4 && \
				total->res_arr[i + 2] && total->res_arr[i + 2] == 7)
			{
				total->res_arr[i] = 1;
				total->res_arr[i + 1] = 4;
				j = i + 2;
				while (total->res_arr[j + 1])
				{
					total->res_arr[j] = total->res_arr[j + 1];
					j++;
				}
				total->res_arr[j] = 0;
				// write(1, "rra\n", 4);
				// write(1, "sa\n", 3);
				i += 2;
				changed = 1;
			}
			if (total->res_arr[i] == 6 && total->res_arr[i + 1] && total->res_arr[i + 1] == 3 && \
				total->res_arr[i + 2] && total->res_arr[i + 2] == 8)
			{
				total->res_arr[i] = 2;
				total->res_arr[i + 1] = 3;
				j = i + 2;
				while (total->res_arr[j + 1])
				{
					total->res_arr[j] = total->res_arr[j + 1];
					j++;
				}
				total->res_arr[j] = 0;
				// write(1, "rra\n", 4);
				// write(1, "sa\n", 3);
				i += 2;
				changed = 1;
			}
			else
				i++;
		}
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
9:	ss
10:	rr
11:	rrr
*/
		i = -1;
		while (total->res_arr[++i])
		{
			if (total->res_arr[i] == 1)
				write(1, "sa\n", 3);
			else if (total->res_arr[i] == 2)
				write(1, "sb\n", 3);
			else if (total->res_arr[i] == 3)
				write(1, "pa\n", 3);
			else if (total->res_arr[i] == 4)
				write(1, "pb\n", 3);
			else if (total->res_arr[i] == 5)
				write(1, "ra\n", 3);
			else if (total->res_arr[i] == 6)
				write(1, "rb\n", 3);
			else if (total->res_arr[i] == 7)
				write(1, "rra\n", 4);
			else if (total->res_arr[i] == 8)
				write(1, "rrb\n", 4);
			else if (total->res_arr[i] == 9)
				write(1, "ss\n", 3);
			else if (total->res_arr[i] == 10)
				write(1, "rr\n", 3);
			else if (total->res_arr[i] == 11)
				write(1, "rrr\n", 4);
		}
		
		// i = write_swap(total, i);
		// i = write_push(total, i);
		// i = write_rotate(total, i);
		// i = write_rev_rotate(total, i);
}
