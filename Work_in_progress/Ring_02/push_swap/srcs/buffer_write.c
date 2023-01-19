/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_write.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 03:17:22 by touteiro          #+#    #+#             */
/*   Updated: 2023/01/19 03:22:02 by touteiro         ###   ########.fr       */
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
	if ((total->log[i] == RA && \
		total->log[i + 1] && total->log[i + 1] == RB) || \
		(total->log[i] == RB && \
		total->log[i + 1] && total->log[i + 1] == RA))
	{
		total->log[i] = RR;
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
	if ((total->log[i] == RA && total->log[i + 1] && \
		total->log[i + 1] == RRA) || (total->log[i] == RB && total->log[i + 1] \
		&& total->log[i + 1] == RRB) || (total->log[i] == RRA && \
		total->log[i + 1] && total->log[i + 1] == RA) || \
		(total->log[i] == RRB && total->log[i + 1] && \
		total->log[i + 1] == RB) || (total->log[i] == PA && \
		total->log[i + 1] && total->log[i + 1] == PB) || \
		(total->log[i] == PB && total->log[i + 1] && \
		total->log[i + 1] == PA) || (total->log[i] == SA && \
		total->log[i + 1] && total->log[i + 1] == SA) || \
		(total->log[i] == SB && total->log[i + 1] && \
		total->log[i + 1] == SB) || (total->log[i] == SS && \
		total->log[i + 1] && total->log[i + 1] == SS) || \
		(total->log[i] == RR && \
		total->log[i + 1] && total->log[i + 1] == RRR) || \
		(total->log[i] == RRR && total->log[i + 1] && total->log[i + 1] == RR))
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
		if (total->log[i] == SA)
			write(1, "sa\n", 3);
		else if (total->log[i] == SB)
			write(1, "sb\n", 3);
		else if (total->log[i] == PA)
			write(1, "pa\n", 3);
		else if (total->log[i] == PB)
			write(1, "pb\n", 3);
		else if (total->log[i] == RA)
			write(1, "ra\n", 3);
		else if (total->log[i] == RB)
			write(1, "rb\n", 3);
		else if (total->log[i] == RRA)
			write(1, "rra\n", 4);
		else if (total->log[i] == RRB)
			write(1, "rrb\n", 4);
		else if (total->log[i] == SS)
			write(1, "ss\n", 3);
		else if (total->log[i] == RR)
			write(1, "rr\n", 3);
		else if (total->log[i] == RRR)
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
