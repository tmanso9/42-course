/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:13:47 by touteiro          #+#    #+#             */
/*   Updated: 2023/01/19 03:30:33 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	size_two_a(t_stack *total)
{
	if (is_sorted(total))
		return ;
	swap(total->a[0], total->a[1], total);
	update_arr(total, SA);
}
