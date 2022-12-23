/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_write.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:45:07 by touteiro          #+#    #+#             */
/*   Updated: 2022/12/23 02:20:42 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	opt_rot_both(t_stack *total, int i, int j, int *changed)
{
	if ((total->log[i] == 5 && \
		total->log[i + 1] && total->log[i + 1] == 6) || \
		(total->log[i] == 6 && \
		total->log[i + 1] && total->log[i + 1] == 5))
	{
		total->log[i] = 10;
		j = i + 1;
		while (total->log[j + 1])
		{
			total->log[j] = total->log[j + 1];
			j++;
		}
		total->log[j] = 0;
		i += 1;
		*changed = 1;
	}
	return (i);
}

int	opt_redundant(t_stack *total, int i, int j, int *changed)
{
	if ((total->log[i] == 5 && total->log[i + 1] && total->log[i + 1] == 7) || \
		(total->log[i] == 6 && total->log[i + 1] && total->log[i + 1] == 8) || \
		(total->log[i] == 7 && total->log[i + 1] && total->log[i + 1] == 5) || \
		(total->log[i] == 8 && total->log[i + 1] && total->log[i + 1] == 6) || \
		(total->log[i] == 3 && total->log[i + 1] && total->log[i + 1] == 4) || \
		(total->log[i] == 4 && total->log[i + 1] && total->log[i + 1] == 3) || \
		(total->log[i] == 1 && total->log[i + 1] && total->log[i + 1] == 1) || \
		(total->log[i] == 2 && total->log[i + 1] && total->log[i + 1] == 2) || \
		(total->log[i] == 9 && total->log[i + 1] && total->log[i + 1] == 9) || \
		(total->log[i] == 10 && \
		total->log[i + 1] && total->log[i + 1] == 11) || \
		(total->log[i] == 11 && total->log[i + 1] && total->log[i + 1] == 10))
	{
		j = i - 1;
		while (total->log[++j + 2])
			total->log[j] = total->log[j + 2];
		total->log[j] = 0;
		i += 1;
		*changed = 1;
	}
	return (i);
}

void	final_write(t_stack *total, int i)
{
	while (total->log[++i])
	{
		if (total->log[i] == 1)
			write(1, "sa\n", 3);
		else if (total->log[i] == 2)
			write(1, "sb\n", 3);
		else if (total->log[i] == 3)
			write(1, "pa\n", 3);
		else if (total->log[i] == 4)
			write(1, "pb\n", 3);
		else if (total->log[i] == 5)
			write(1, "ra\n", 3);
		else if (total->log[i] == 6)
			write(1, "rb\n", 3);
		else if (total->log[i] == 7)
			write(1, "rra\n", 4);
		else if (total->log[i] == 8)
			write(1, "rrb\n", 4);
		else if (total->log[i] == 9)
			write(1, "ss\n", 3);
		else if (total->log[i] == 10)
			write(1, "rr\n", 3);
		else if (total->log[i] == 11)
			write(1, "rrr\n", 4);
	}
}

int	optimize_log(t_stack *total, int i, int j, int changed)
{
	changed = 0;
	if (!(total->log[i]))
		i = 0;
	while (total->log[i])
	{
		j = i;
		i = opt_revsb(total, i, j, &changed);
		i = opt_revsa(total, i, j, &changed);
		i = opt_swap_both(total, i, j, &changed);
		i = opt_rot_both(total, i, j, &changed);
		i = opt_redundant(total, i, j, &changed);
		i = opt_sa_pb(total, i, j, &changed);
		i = opt_sb_pa(total, i, j, &changed);
		if (j == i)
			i++;
	}
	return (changed);
}

void	write_output(t_stack *total)
{
	int	i;
	int	j;
	int	changed;

	i = 0;
	changed = 1;
	j = 0;
	while (changed)
		changed = optimize_log(total, i, j, changed);
	i = -1;
	final_write(total, i);
}
