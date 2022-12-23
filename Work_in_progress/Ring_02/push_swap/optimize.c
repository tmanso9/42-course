/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 02:20:16 by touteiro          #+#    #+#             */
/*   Updated: 2022/12/23 02:26:12 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	opt_revsa(t_stack *total, int i, int j, int *changed)
{
	if (total->log[i] == 4 && \
		total->log[i + 1] && total->log[i + 1] == 7 && \
		total->log[i + 2] && total->log[i + 2] == 3)
	{
		total->log[i] = 7;
		total->log[i + 1] = 1;
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
	if (total->log[i] == 3 && \
		total->log[i + 1] && total->log[i + 1] == 8 && \
		(total->log[i + 2] && total->log[i + 2] == 4))
	{
		total->log[i] = 8;
		total->log[i + 1] = 2;
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
	if (total->log[i] == 5 && \
		total->log[i + 1] && total->log[i + 1] == 4 && \
		total->log[i + 2] && total->log[i + 2] == 7)
	{
		total->log[i] = 1;
		total->log[i + 1] = 4;
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
	if (total->log[i] == 6 && \
		total->log[i + 1] && total->log[i + 1] == 3 && \
		total->log[i + 2] && total->log[i + 2] == 8)
	{
		total->log[i] = 2;
		total->log[i + 1] = 3;
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
	if ((total->log[i] == 1 && \
		total->log[i + 1] && total->log[i + 1] == 2) || \
		(total->log[i] == 2 && \
		total->log[i + 1] && total->log[i + 1] == 1))
	{
		total->log[i] = 9;
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
