/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:18:08 by touteiro          #+#    #+#             */
/*   Updated: 2022/11/22 18:47:58 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	main()
{
	int **arr;
	int	size;

	int i = -1;
	size = 3;	
	arr = (int **)malloc(sizeof(int *) * (size + 1));
	arr[size] = 0;
	while (++i < size)
		arr[i] = (int *)malloc(sizeof(int));
	*arr[0] = 2;
	*arr[1] = -10;
	*arr[2] = 5;
	//{2, -10, 5};
	
	int	temp;
	i = -1;
	int j = 0;
	int **sorted_arr;
	
	sorted_arr = (int **)malloc(sizeof(int *) * (size + 1));
	while (++i < size)
	{
		sorted_arr[i] = (int *)malloc(sizeof(int));
		*sorted_arr[i] = *arr[i];
	}
	i = -1;
	while (++i < 2)
	{
		while (++j < 3)
		{
			if (*sorted_arr[i] > *sorted_arr[j])
			{
				temp = *sorted_arr[i];
				*sorted_arr[i] = *sorted_arr[j];
				*sorted_arr[j] = temp;
			}
		}
		j = i + 1;
	}
	
	int **index_arr;

	i = -1;
	index_arr = (int **)malloc(sizeof(int *) * (size + 1));
	while (++i < size)
		index_arr[i] = (int *)malloc(sizeof(int));
	i = -1;
	j = -1;
	while (++i < 3)
	{
		while (++j < 3)
		{
			if (*arr[i] == *sorted_arr[j])
				*index_arr[i] = j + 1;
		}
		j = -1;
	}
	printf("%d\n", *index_arr[0]);
	printf("%d\n", *index_arr[1]);
	printf("%d\n", *index_arr[2]);
}
