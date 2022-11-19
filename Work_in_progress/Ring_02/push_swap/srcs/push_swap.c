/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 23:53:05 by touteiro          #+#    #+#             */
/*   Updated: 2022/11/19 01:14:43 by touteiro         ###   ########.fr       */
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

int	check_digits(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			printf("Invalid argument! %s isn't a number.\n", str);
			return (0);
		}
		i++;
	}
	return (1);
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

int	check_limits(char *str)
{
	if (str[0] == '-' && ft_strlen(str) > 10 && \
		ft_strncmp("-2147483648", str, 12) < 0)
	{
		printf("Invalid argument! %s is too small.\n", str);
		return (0);
	}
	else if ((ft_strlen(str) > 9 && \
		ft_strncmp("2147483647", str, 11) < 0) || \
		(str[0] != '-' && ft_strlen(str) > 10))
	{
		printf("Invalid argument! %s is too big.\n", str);
		return (0);
	}
	return (1);
}

int	**process_args(int argc, char **argv, int **a)
{
	int		i;
	char	**nums;

	i = 0;
	nums = 0;
	if (argc == 2)
	{
		nums = ft_split(argv[1], ' ');
		while (nums[i])
		{
			/*Add a general check function so it prints all errors*/
			if (!check_limits(nums[i]) || !check_doubles(nums) || \
				!check_digits(nums[i]))
			{
				i = -1;
				while (nums[++i])
					free(nums[i]);
				free(nums);
				return (a);
			}
			i++;
		}
		a = ft_calloc(i + 1, sizeof(int *));
		i = -1;
		while (nums[++i])
		{
			a[i] = ft_calloc(1, sizeof(int));
			*a[i] = ft_atoi(nums[i]);
			free(nums[i]);
		}
		free(nums);
	}
	else
	{
		while (argc > ++i)
			if (!check_limits(argv[i]) || \
				!check_doubles(argv) || \
				!check_digits(argv[i]))
				return (a);
		i = 0;
		a = ft_calloc(argc, sizeof(int *));
		while (argc > ++i)
		{
			a[i - 1] = ft_calloc(1, sizeof(int));
			*a[i - 1] = ft_atoi(argv[i]);
		}
	}
	return (a);
}

int	main(int argc, char **argv)
{
	int	**a;
	//int	**b;
	int	i;

	i = 0;
	a = NULL;
	if (argc < 2)
	{
		(void)argv;
		write(1, "Must have at least one argument!\n", 33);
		return (0);
	}
	a = process_args(argc, argv, a);
	if (!a)
		return (0);
	while (a[i])
	{
		printf("%d\n", *a[i]);
		free(a[i]);
		i++;
	}
	free(a);
}
