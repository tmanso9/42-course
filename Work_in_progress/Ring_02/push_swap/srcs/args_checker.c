/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:39:04 by touteiro          #+#    #+#             */
/*   Updated: 2023/01/20 12:12:34 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	process_two_args(t_stack *total, char **nums, int i)
{
	if (!check_args(nums))
	{
		write(2, "Error\n", 6);
		clean_exit(total, nums);
	}
	while (nums[i])
		i++;
	total->a_size = i;
	total->curr_a_size = total->a_size;
	total->a = ft_calloc(i + 1, sizeof(int *));
	total->b = ft_calloc(i + 1, sizeof(int *));
	total->log = ft_calloc((i * i * 2 / 3), sizeof(char));
	if (!total->a || !total->b || !total->log)
		clean_exit(total, nums);
	i = -1;
	while (nums[++i])
	{
		total->a[i] = ft_calloc(1, sizeof(int));
		if (!total->a[i])
			clean_exit(total, nums);
		*(total->a[i]) = ft_atoi(nums[i]);
	}
	free_nums(nums);
}

char	*join_all(char **argv, char *full_args)
{
	char	*temp;
	int		i;

	i = 1;
	full_args = ft_strdup(argv[1]);
	while (argv[++i])
	{
		temp = ft_strjoin(full_args, " ");
		free (full_args);
		full_args = ft_strjoin(temp, argv[i]);
		free (temp);
	}
	return (full_args);
}

void	process_args(char **argv, t_stack *total)
{
	int		i;
	char	**nums;
	char	*full_args;

	i = 0;
	nums = NULL;
	full_args = NULL;
	full_args = join_all(argv, full_args);
	nums = ft_split(full_args, ' ');
	free(full_args);
	if (!nums)
		return ;
	process_two_args(total, nums, i);
}
