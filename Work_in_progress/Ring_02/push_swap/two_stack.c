/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:13:47 by touteiro          #+#    #+#             */
/*   Updated: 2022/12/14 14:05:55 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	size_two_a(t_stack *total)
{
	if (is_sorted(total))
		return ;
	swap(total->a[0], total->a[1]);
	update_arr(total, 1);
}
