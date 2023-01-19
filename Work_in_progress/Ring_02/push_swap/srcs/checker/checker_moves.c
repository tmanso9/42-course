/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 23:51:39 by touteiro          #+#    #+#             */
/*   Updated: 2022/12/26 16:30:28 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
 * It checks if the string is a reverse rotate command,
 * and if it is, it executes it
 * 
 * @param final the final stack
 * @param str the string to check
 * 
 * @return 1 if the string is a reverse rotate command, 0 if not.
 */
int	check_rev_rotate(t_stack *final, char *str)
{
	if (!(ft_strncmp("rra\n", str, 4)))
	{
		rev_rot(final, 'a', final->a, final->curr_a_size);
		return (1);
	}
	else if (!(ft_strncmp("rrb\n", str, 4)))
	{
		if (final->curr_b_size)
			rev_rot(final, 'b', final->b, final->curr_b_size);
		return (1);
	}
	else if (!(ft_strncmp("rrr\n", str, 4)))
	{
		rev_rot(final, 'a', final->a, final->curr_a_size);
		if (final->curr_b_size)
			rev_rot(final, 'b', final->b, final->curr_b_size);
		return (1);
	}
	return (0);
}

/*
 * It checks if the string is a rotate command, and if it is,
 * it executes the rotate command
 * 
 * @param final the final stack that will be checked
 * @param str the string to check
 * 
 * @return 1 if the str is a commmand to rotate, 0 if it is not.
 */
int	check_rotate(t_stack *final, char *str)
{
	if (!(ft_strncmp("ra\n", str, 4)))
	{
		rot(final, 'a', final->a, final->curr_a_size);
		return (1);
	}
	else if (!(ft_strncmp("rb\n", str, 4)))
	{
		if (final->curr_b_size)
			rot(final, 'b', final->b, final->curr_b_size);
		return (1);
	}
	else if (!(ft_strncmp("rr\n", str, 4)))
	{
		rot(final, 'a', final->a, final->curr_a_size);
		rot(final, 'b', final->b, final->curr_b_size);
		return (1);
	}
	return (0);
}

/*
 * It checks if the string is a push command, and if it is,
 * it executes it
 * 
 * @param final the final stack that will be sorted
 * @param str the string that is being checked
 * 
 * @return 1 if the string is a push, 0 if not.
 */
int	check_push(t_stack *final, char *str)
{
	if (!(ft_strncmp("pa\n", str, 4)))
	{
		if (final->curr_b_size)
			pa(final);
		return (1);
	}
	else if (!(ft_strncmp("pb\n", str, 4)))
	{
		pb(final);
		return (1);
	}
	return (0);
}

/*
 * It checks if the string is a swap command, and if it is,
 * it executes the swap command
 * 
 * @param final the final stack
 * @param str the string that is being checked
 * 
 * @return 1 if the command was a swap, 0 if not.
 */
int	check_swap(t_stack *final, char *str)
{
	if (!(ft_strncmp("sa\n", str, 4)))
	{
		swap(final->a[0], final->a[1], final);
		return (1);
	}
	else if (!(ft_strncmp("sb\n", str, 4)))
	{
		if (final->curr_b_size)
			swap(final->b[final->a_size - final->curr_b_size], \
				final->b[final->a_size - final->curr_b_size + 1], final);
		return (1);
	}
	else if (!(ft_strncmp("ss\n", str, 4)))
	{
		swap(final->a[0], final->a[1], final);
		if (final->curr_b_size)
			swap(final->b[final->a_size - final->curr_b_size], \
				final->b[final->a_size - final->curr_b_size + 1], final);
		return (1);
	}
	return (0);
}

/*
 * It checks if the string is a valid move, and if it is,
 * it performs the move
 * 
 * @param final the final stack that we want to change
 * @param str the string that is being checked
 */
int	check_moves(t_stack *final, char *str)
{
	if (!(check_swap(final, str)) && !(check_push(final, str)) && \
		!(check_rotate(final, str)) && !(check_rev_rotate(final, str)))
		return (0);
	return (1);
}
