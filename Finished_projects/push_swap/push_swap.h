/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 12:56:22 by touteiro          #+#    #+#             */
/*   Updated: 2022/12/14 14:10:38 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/incs/libft.h"

typedef struct s_stack
{
	int		**a;
	int		**b;
	int		a_size;
	int		curr_a_size;
	int		curr_b_size;
	int		a_median;
	int		b_median;
	int		rev;
	int		len;
	char	*res_arr;
	int		index;
}	t_stack;

// Initialize stacks and process arguments
void	init_stacks(t_stack *total);
void	free_stacks(t_stack *total);
void	process_args(int argc, char **argv, t_stack *total);
int		check_args(char **nums);

// Process small a stack
int		is_sorted(t_stack *total);
void	size_two_a(t_stack *total);
void	size_three_a(t_stack *total);
void	size_five_a(t_stack *total);

// Moves and utils
void	rot(t_stack *total, char id, int **stack, int size);
void	rev_rot(t_stack *total, char id, int **stack, int size);
void	swap(int *a, int *b);
void	pa(t_stack *total);
void	pb(t_stack *total);
int		smallest(int **arr, int stack_size);
int		biggest(t_stack *total);

// Quicksort for medium and big arrays
void	quicksort_a(t_stack *total, int len);
int		find_median(int **arr, int len);
void	quicksort_b(t_stack *total, int len);
void	size_two_b(t_stack *total);
void	size_three_b(t_stack *total);
void	size_four_b(t_stack *total);
int		find_b_median(t_stack *total, int len);
int		b_is_sorted(t_stack *total);

// Update buffer and write it
void	update_arr(t_stack *total, char code);
void	write_output(t_stack *total);

#endif