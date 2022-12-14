/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:39:04 by touteiro          #+#    #+#             */
/*   Updated: 2022/12/14 14:04:43 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	process_multiple_args(int argc, char **argv, t_stack *total, int i)
{
	if (!check_args(argv + 1))
	{
		write(2, "Error\n", 6);
		total->a = 0;
		return ;
	}
	total->a_size = argc - 1;
	total->curr_a_size = total->a_size;
	total->a = (int **)malloc(sizeof(int *) * (total->a_size + 1));
	total->b = (int **)malloc(sizeof(int *) * (total->a_size + 1));
	total->res_arr = ft_calloc(((argc - 1) * (argc - 1) * 2 / 3), sizeof(char));
	total->a[total->a_size] = NULL;
	total->b[total->a_size] = NULL;
	while (argc > ++i)
	{
		total->a[i - 1] = (int *)malloc(sizeof(int));
		*(total->a[i - 1]) = ft_atoi(argv[i]);
	}
}

static void	process_two_args(t_stack *total, char **nums, int i)
{
	if (!check_args(nums))
	{
		write(2, "Error\n", 6);
		i = -1;
		while (nums[++i])
			free(nums[i]);
		free(nums);
		total->a = 0;
		return ;
	}
	while (nums[i])
		i++;
	total->a_size = i;
	total->curr_a_size = total->a_size;
	total->a = ft_calloc(i + 1, sizeof(int *));
	total->b = ft_calloc(i + 1, sizeof(int *));
	total->res_arr = ft_calloc((i * i * 2 / 3), sizeof(char));
	i = -1;
	while (nums[++i])
	{
		total->a[i] = ft_calloc(1, sizeof(int));
		*(total->a[i]) = ft_atoi(nums[i]);
		free(nums[i]);
	}
	free(nums);
}

void	process_args(int argc, char **argv, t_stack *total)
{
	int		i;
	char	**nums;

	i = 0;
	nums = 0;
	if (argc == 2)
	{
		nums = ft_split(argv[1], ' ');
		process_two_args(total, nums, i);
	}
	else
		process_multiple_args(argc, argv, total, i);
}
