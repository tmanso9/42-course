/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 02:25:28 by touteiro          #+#    #+#             */
/*   Updated: 2022/12/26 16:43:30 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/**
 * It checks if the moves are valid, and if they are,
 * it performs them, frees the string and gets the next line
 * 
 * @param final the final stack
 * @param str the string that contains the moves
 * @param pipe if the program is being run with a pipe,
 * this will be 1. Otherwise, it will be 0.
 * 
 * @return A pointer to the next line.
 */
char	*do_moves(t_stack *final, char *str, char pipe)
{
	if (!check_moves(final, str))
	{
		write(2, "Error\n", 6);
		free (str);
		clean_exit(final, 0);
	}	
	free(str);
	if (pipe)
		str = get_next_line(0);
	else
		str = get_next_line(1);
	return (str);
}

/*
If get_next_line with fd 0 exists, then we are reading from a push swap
program output. Else, we are reading instructions from the terminal.
*/
void	apply_move_list(t_stack *final, char *str, char pipe)
{
	if (str)
		pipe = 1;
	else
		str = get_next_line(1);
	while (str)
		str = do_moves(final, str, pipe);
	free (str);
}

/* 
Check if with sorted input the push swap program prints any instructions.
*/
void	check_sorted_input(t_stack *final, char *str)
{
	ft_printf("%s", str);
	if (is_sorted(final))
	{
		if (!str)
		{
			ft_printf("OK\n");
			clean_exit(final, 0);
		}
		else
		{
			ft_printf("KO\n");
			clean_exit(final, 0);
		}
	}
}

/*
 * It initializes the stacks, processes the arguments,
 * checks if the input is sorted, applies the move
 * list, and cleans up
 */
int	main(int argc, char **argv)
{
	t_stack	*final;
	char	*str;

	if (argc < 2 || (argc == 2 && !ft_strlen(argv[1])))
		return (0);
	final = ft_calloc(1, sizeof(t_stack));
	if (!final)
		return (0);
	init_stacks(final);
	process_args(argc, argv, final);
	str = get_next_line(0);
	check_sorted_input(final, str);
	apply_move_list(final, str, 0);
	if (is_sorted(final))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	clean_exit(final, 0);
}
