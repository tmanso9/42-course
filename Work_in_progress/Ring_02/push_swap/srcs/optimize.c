/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 02:20:16 by touteiro          #+#    #+#             */
/*   Updated: 2023/01/19 03:29:41 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	opt_revsa(t_stack *total, int i, int j, int *changed)
{
	if (total->log[i] == PB && \
		total->log[i + 1] && total->log[i + 1] == RRA && \
		total->log[i + 2] && total->log[i + 2] == PA)
	{
		total->log[i] = RRA;
		total->log[i + 1] = SA;
		j = i + 2;
		while (total->log[j + 1])
		{
			total->log[j] = total->log[j + 1];
			j++;
		}
		total->log[j] = 0;
		i += 2;
		*changed = 1;
	}
	return (i);
}

int	opt_revsb(t_stack *total, int i, int j, int *changed)
{
	if (total->log[i] == PA && \
		total->log[i + 1] && total->log[i + 1] == RRB && \
		(total->log[i + 2] && total->log[i + 2] == PB))
	{
		total->log[i] = RRB;
		total->log[i + 1] = SB;
		j = i + 2;
		while (total->log[j + 1])
		{
			total->log[j] = total->log[j + 1];
			j++;
		}
		total->log[j] = 0;
		i += 2;
		*changed = 1;
	}
	return (i);
}

int	opt_sa_pb(t_stack *total, int i, int j, int *changed)
{
	if (total->log[i] == RA && \
		total->log[i + 1] && total->log[i + 1] == PB && \
		total->log[i + 2] && total->log[i + 2] == RRA)
	{
		total->log[i] = SA;
		total->log[i + 1] = PB;
		j = i + 2;
		while (total->log[j + 1])
		{
			total->log[j] = total->log[j + 1];
			j++;
		}
		total->log[j] = 0;
		i += 2;
		*changed = 1;
	}
	return (i);
}

int	opt_sb_pa(t_stack *total, int i, int j, int *changed)
{
	if (total->log[i] == RB && \
		total->log[i + 1] && total->log[i + 1] == PA && \
		total->log[i + 2] && total->log[i + 2] == RRB)
	{
		total->log[i] = SB;
		total->log[i + 1] = PA;
		j = i + 2;
		while (total->log[j + 1])
		{
			total->log[j] = total->log[j + 1];
			j++;
		}
		total->log[j] = 0;
		i += 2;
		*changed = 1;
	}
	return (i);
}

int	opt_swap_both(t_stack *total, int i, int j, int *changed)
{
	if ((total->log[i] == SA && \
		total->log[i + 1] && total->log[i + 1] == SB) || \
		(total->log[i] == SB && \
		total->log[i + 1] && total->log[i + 1] == SA))
	{
		total->log[i] = SS;
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
