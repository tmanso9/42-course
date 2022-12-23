/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:39:04 by touteiro          #+#    #+#             */
/*   Updated: 2022/12/23 03:06:19 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	process_multiple_args(int argc, char **argv, t_stack *total, int i)
{
	if (!check_args(argv + 1))
	{
		write(2, "Error\n", 6);
		clean_exit(total);
	}
	total->a_size = argc - 1;
	total->curr_a_size = total->a_size;
	total->a = ft_calloc(argc, sizeof(int *));
	total->b = ft_calloc(argc, sizeof(int *));
	total->log = ft_calloc(((argc - 1) * (argc - 1) * 2 / 3), sizeof(char));
	if (!total->a || !total->b || !total->log)
		clean_exit(total);
	total->a[total->a_size] = NULL;
	total->b[total->a_size] = NULL;
	while (argc > ++i)
	{
		total->a[i - 1] = ft_calloc(1, sizeof(int));
		if (!total->a[i - 1])
			clean_exit(total);
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
		clean_exit(total);
	}
	while (nums[i])
		i++;
	total->a_size = i;
	total->curr_a_size = total->a_size;
	total->a = ft_calloc(i + 1, sizeof(int *));
	total->b = ft_calloc(i + 1, sizeof(int *));
	total->log = ft_calloc((i * i * 2 / 3), sizeof(char));
	if (!total->a || !total->b || !total->log)
	{
		i = -1;
		while (nums[++i])
			free (nums[i]);
		free(nums);
		clean_exit(total);
	}
	i = -1;
	while (nums[++i])
	{
		total->a[i] = ft_calloc(1, sizeof(int));
		if (!total->a[i])
		{
			free(nums[i]);
			free(nums);
			clean_exit(total);
		}
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
		if (!nums)
			return ;
		process_two_args(total, nums, i);
	}
	else
		process_multiple_args(argc, argv, total, i);
}
