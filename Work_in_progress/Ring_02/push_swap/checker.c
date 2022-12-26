/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 02:25:28 by touteiro          #+#    #+#             */
/*   Updated: 2022/12/26 16:54:49 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
 * It checks if the moves are valid and if they are
 * it performs them, frees the string and gets the next line
 * 
 * returns A pointer to the next line.
 */
char	*do_moves(t_stack *final, char *str)
{
	if (!check_moves(final, str))
	{
		write(2, "Error\n", 6);
		free (str);
		clean_exit(final, 0);
	}	
	free(str);
	str = get_next_line(0);
	return (str);
}


/*
 * It takes a string of moves and applies them to a stack
 */
void	apply_move_list(t_stack *final, char *str)
{
	while (str)
		str = do_moves(final, str);
	free (str);
}

/* 
Check if with sorted input the push swap program prints any instructions.
*/
void	check_sorted_input(t_stack *final, char *str)
{
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
	apply_move_list(final, str);
	if (is_sorted(final))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	clean_exit(final, 0);
}
