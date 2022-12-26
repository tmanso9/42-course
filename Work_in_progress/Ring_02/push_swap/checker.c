/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 02:25:28 by touteiro          #+#    #+#             */
/*   Updated: 2022/12/24 02:01:49 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

int	main(int argc, char **argv)
{
	t_stack	*final;
	char	*str;
	char	pipe;

	if (argc < 2 || (argc == 2 && !ft_strlen(argv[1])))
		return (0);
	final = ft_calloc(1, sizeof(t_stack));
	if (!final)
		return (0);
	init_stacks(final);
	process_args(argc, argv, final);
	pipe = 0;
	str = get_next_line(0);
	if (str)
		pipe = 1;
	else
		str = get_next_line(1);
	while (str)
		str = do_moves(final, str, pipe);
	free (str);
	if (is_sorted(final))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	clean_exit(final, 0);
}
