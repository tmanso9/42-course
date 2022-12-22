/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 23:53:05 by touteiro          #+#    #+#             */
/*   Updated: 2022/12/14 15:38:31 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*total;

	if (argc < 2)
		return (0);
	if (argc == 2 && !ft_strlen(argv[1]))
		return (0);
	total = malloc(sizeof(t_stack));
	if (!total)
		return (0);
	init_stacks(total);
	process_args(argc, argv, total);
	if (total->a_size == 2 && !is_sorted(total))
		size_two_a(total);
	else if (total->a_size == 3 && !is_sorted(total))
		size_three_a(total);
	else if (total->a_size >= 4 && total->a_size < 9 && !is_sorted(total))
		size_five_a(total);
	else if (total->a_size >= 9 && !is_sorted(total))
		quicksort_a(total, total->a_size);
	if (total->a_size > 1 && total->res_arr[0])
		write_output(total);
	free_stacks(total);
}
