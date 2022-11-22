/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 12:56:22 by touteiro          #+#    #+#             */
/*   Updated: 2022/11/22 15:23:45 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int	**a;
	int	**b;
	int	a_size;
	int	curr_a_size;
	int	curr_b_size;
}	t_stack;

void	init_stacks(t_stack *total);
void	size_two(t_stack *total);
void	size_three(t_stack *total);
void	size_four(t_stack *total);
void	size_five(t_stack *total);
int		is_sorted(t_stack *total);
int		smallest(int **arr, int stack_size);

#endif