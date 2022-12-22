/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_valid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:44:53 by touteiro          #+#    #+#             */
/*   Updated: 2022/12/14 14:04:47 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_digits(char **nums)
{
	int	i;
	int	j;
	int	digits;

	i = 0;
	j = -1;
	digits = 0;
	while (nums[i])
	{
		if (nums[i][++j] == '-' || nums[i][j] == '+')
			if (!nums[i][++j])
				return (0);
		while (nums[i][j])
		{
			if (!ft_isdigit(nums[i][j]))
				return (0);
			digits++;
			j++;
		}
		i++;
		j = -1;
	}
	if (!digits)
		return (0);
	return (1);
}

static int	check_doubles(char **nums, int advanced1, int advanced2)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (nums[i])
	{
		while (nums[j])
		{
			advanced1 = 0;
			advanced2 = 0;
			if (nums[i][0] == '+')
				advanced1 = 1;
			if (nums[j][0] == '+')
				advanced2 = 1;
			if (ft_strncmp(nums[i] + advanced1, nums[j] + advanced2, \
				return_biggest(ft_strlen(nums[i] + advanced1), \
				ft_strlen(nums[j] + advanced2))) == 0)
				return (0);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (1);
}

static int	check_limits(char **nums)
{
	int	i;

	i = 0;
	while (nums[i])
	{
		if (nums[i][0] == '-' && ft_strlen(nums[i]) > 10 && \
			ft_strncmp("-2147483648", nums[i], 12) < 0)
			return (0);
		else if ((ft_strlen(nums[i]) > 9 && \
			ft_strncmp("2147483647", nums[i], 11) < 0) || \
			(nums[i][0] != '-' && ft_strlen(nums[i]) > 10))
			return (0);
		i++;
	}
	return (1);
}

int	check_args(char **nums)
{
	int	res;
	int	advanced1;
	int	advanced2;

	res = 1;
	advanced1 = 0;
	advanced2 = 0;
	if (!check_doubles(nums, advanced1, advanced2))
		return (0);
	if (!check_limits(nums))
		return (0);
	if (!check_digits(nums))
		return (0);
	return (res);
}
