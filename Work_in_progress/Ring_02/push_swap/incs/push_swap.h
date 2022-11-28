/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 12:56:22 by touteiro          #+#    #+#             */
/*   Updated: 2022/11/25 19:56:46 by touteiro         ###   ########.fr       */
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
int		biggest(t_stack *total);
void	quicksort_a(t_stack *total, int len);
void	quicksort_b(t_stack *total, int len);
void	rot(t_stack *total, char id, int **stack, int size);
void	rev_rot(t_stack *total, char id, int **stack, int size);
void	swap(int *a, int *b);
void	pa(t_stack *total);
void	pb(t_stack *total);

#endif