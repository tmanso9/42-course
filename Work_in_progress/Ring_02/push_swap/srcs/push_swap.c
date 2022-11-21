/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 23:53:05 by touteiro          #+#    #+#             */
/*   Updated: 2022/11/19 21:08:16 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"
#include "../libft/libft.h"

int	return_biggest(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	check_digits(char **nums)
{
	int	i;
	int	j;
	int	res;

	i = 0;
	j = 0;
	res = 1;
	while (nums[i])
	{
		if (nums[i][0] == '-')
			j = 1;
		while (nums[i][j])
		{
			if (!ft_isdigit(nums[i][j]))
			{
				printf("Invalid arguments! %s isn't a number.\n", nums[i]);
				res = 0;
			}
			j++;
		}
		i++;
		j = 0;
	}
	return (res);
}

int	check_doubles(char **nums)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (nums[i])
	{
		while (nums[j])
		{
			if (ft_strncmp(nums[i], nums[j], \
				return_biggest(ft_strlen(nums[i]), ft_strlen(nums[j]))) == 0)
			{
				printf("Invalid arguments! Can't have duplicates.\n");
				return (0);
			}
			j++;
		}
		i++;
		j = i + 1;
	}
	return (1);
}

int	check_limits(char **nums)
{
	int	i;

	i = 0;
	while (nums[i])
	{
		if (nums[i][0] == '-' && ft_strlen(nums[i]) > 10 && \
			ft_strncmp("-2147483648", nums[i], 12) < 0)
		{
			printf("Invalid arguments! %s is too small.\n", nums[i]);
			return (0);
		}
		else if ((ft_strlen(nums[i]) > 9 && \
			ft_strncmp("2147483647", nums[i], 11) < 0) || \
			(nums[i][0] != '-' && ft_strlen(nums[i]) > 10))
		{
			printf("Invalid arguments! %s is too big.\n", nums[i]);
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_args(char **nums)
{
	int	res;

	res = 1;
	if (!check_doubles(nums))
		res = 0;
	if (!check_limits(nums))
		res = 0;
	if (!check_digits(nums))
		res = 0;
	return (res);
}

t_stack process_args(int argc, char **argv, t_stack total)
{
	int		i;
	char	**nums;

	i = 0;
	nums = 0;
	if (argc == 2)
	{
		nums = ft_split(argv[1], ' ');
		if (!check_args(nums))
		{
			i = -1;
			while (nums[++i])
				free(nums[i]);
			free(nums);
			//free(total.a);
			total.a = 0;
			return (total);
		}
		while (nums[i])
			i++;
		total.a_size = i;
		//free(total.a);
		total.a = ft_calloc(i + 1, sizeof(int *));
		i = -1;
		while (nums[++i])
		{
			total.a[i] = ft_calloc(1, sizeof(int));
			*(total.a[i]) = ft_atoi(nums[i]);
			free(nums[i]);
		}
		free(nums);
	}
	else
	{
		if (!check_args(argv + 1))
		{
			//free(total.a);
			total.a = 0;
			return (total);
		}
		total.a_size = argc - 1;
		//free(total.a);
		total.a = (int **)malloc(sizeof(int *) * (argc + 1));
		total.a[argc] = NULL;
		while (argc > ++i)
		{
			total.a[i - 1] = (int *)malloc(sizeof(int));
			*(total.a[i - 1]) = ft_atoi(argv[i]);
		}
	}
	return (total);
}

int	main(int argc, char **argv)
{
	t_stack	*total;
	int		i;

	i = 0;
	total = (t_stack *)malloc(sizeof(t_stack));
	init_stacks(total);
	if (argc < 2)
	{
		(void)argv;
		write(1, "Must have at least one argument!\n", 33);
		return (0);
	}
	*total = process_args(argc, argv, *total);
	if (!total->a)
	{
		free(total->a);
		free(total);
		return (0);
	}
	if (total->a_size == 2)
		size_two(total);
	else if (total->a_size == 3)
		size_three(total);
	while (i < total->a_size)
	{
		//printf("%d\n", *total->a[i]);
		free(total->a[i]);
		i++;
	}
	free(total->a);
	free(total);
}
