/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:26:12 by touteiro          #+#    #+#             */
/*   Updated: 2022/11/25 20:56:54 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

void	size_two_b(t_stack *total)
{
	if (*total->b[total->a_size - 2] > *total->b[total->a_size - 1])
		return ;
	swap(total->b[total->a_size - 2], total->b[total->a_size - 1]);
	write(1, "sb\n", 3);
}

void	size_three_b(t_stack *total)
{
	if (*total->b[total->a_size - 3] > \
		*total->b[total->a_size - 2] && \
		*total->b[total->a_size - 2] > \
		*total->b[total->a_size - 1])
		return ;
	if (*total->b[total->a_size - 3] < \
		*total->b[total->a_size - 2] && \
		*total->b[total->a_size - 3] > \
		*total->b[total->a_size - 1])
	{
		swap(total->b[total->a_size - 3], total->b[total->a_size - 2]);
		write(1, "sb\n", 3);
		size_three_b(total);
	}
	else if (*total->b[total->a_size - 3] > \
		*total->b[total->a_size - 2])
	{
		rev_rot(total, 'b', total->b, total->curr_b_size);
		write(1, "rrb\n", 4);
		size_three_b(total);
	}
	else if (*total->b[total->a_size - 3] < \
		*total->b[total->a_size - 2])
	{
		rot(total, 'b', total->b, total->curr_b_size);
		write(1, "rb\n", 3);
		size_three_b(total);
	}
}

void	size_four_b(t_stack *total)
{
	if (*total->b[total->a_size - 4] > \
		*total->b[total->a_size - 3] && \
		*total->b[total->a_size - 3] > \
		*total->b[total->a_size - 2] && \
		*total->b[total->a_size - 2] > \
		*total->b[total->a_size - 1])
		return ;
	if (biggest(total) == total->a_size - 4)
	{
		pa(total);
		write(1, "pa\n", 3);
		size_three_b(total);
		return ;
	}
	else if (biggest(total) > total->a_size - 4 && \
		biggest(total) < total->a_size - 2)
	{
		rot(total, 'b', total->b, total->curr_b_size);
		write(1, "rb\n", 3);
		size_four_b(total);
	}
	else
	{
		rev_rot(total, 'b', total->b, total->curr_b_size);
		write(1, "rrb\n", 4);
		size_four_b(total);
	}
}

int	find_b_median(t_stack *total, int len)
{
	int	i;
	int	j;
	int	lower;
	int	higher;
	int	count;

	i = total->a_size - total->curr_b_size;
	j = i;
	lower = 0;
	higher = 0;
	count = 0;
	while (count < len - 1)
	{
		while (j < total->a_size)
		{
			if (*total->b[i] > *total->b[j])
				lower++;
			if (*total->b[i] < *total->b[j])
				higher++;
			j++;
		}
		if (len % 2 && lower == higher)
			return (*total->b[i]);
		else if (!(len % 2) && higher == len / 2)
			return (*total->b[i]);
		lower = 0;
		higher = 0;
		i++;
		count++;
		j = total->a_size - total->curr_b_size;
	}
	return (*total->b[i]);
}

int	find_median(int **arr, int len)
{
	int	i;
	int	j;
	int	lower;
	int	higher;

	i = 0;
	j = 0;
	lower = 0;
	higher = 0;
	while (i < len - 1)
	{
		while (j < len)
		{
			if (*arr[i] > *arr[j])
				lower++;
			if (*arr[i] < *arr[j])
				higher++;
			j++;
		}
		if (len % 2 && lower == higher)
			return (*arr[i]);
		else if (!(len % 2) && higher == len / 2)
			return (*arr[i]);
		lower = 0;
		higher = 0;
		i++;
		j = 0;
	}
	return (*arr[i]);
}

void	small_stack(t_stack *total)
{
	if (total->curr_a_size == 2)
		size_two(total);
	if (total->curr_a_size == 3)
		size_three(total);
	if (total->curr_a_size == 4)
		size_four(total);
	if (total->curr_a_size >= 5)
		size_five(total);
}

void	quicksort_a(t_stack *total, int len)
{
	int	median;
	int	i;
	//int	count;

	i = 0;
	//printf("got here\n");
	/*while (i < total->curr_a_size)
	{
		printf("%d\n", *total->a[i]);
		i++;
	}*/
	//return ;
	//printf("a size is %d, b size is %d, len is %d\n", total->curr_a_size, total->curr_b_size, len);
	if (is_sorted(total))
		return ;
	if (len < 4)
	{
		size_five(total);
		/*i = 0;
		printf("\nA: \n");
		while (i < total->curr_a_size)
		{
			printf("%d\n", *total->a[i]);
			i++;
		}
		i = total->a_size - total->curr_b_size;
		count = 0;
		printf("\nB: \n");
		//printf("i is %d, b size is %d\n", i, total->curr_b_size);
		while (count < total->curr_b_size)
		{
			printf("%d\n", *total->b[i]);
			i++;
			count++;
		}*/
		return ;
	}
	median = find_median(total->a, len);
	//printf("median is %d, *total->a[0] is %d\n", median, *total->a[0]);
	i = 0;
	while (i < len)
	{
		if (*total->a[0] < median)
		{
			pb(total);
			write(1, "pb\n", 3);
		}
		else
		{
			rot(total, 'a', total->a, total->curr_a_size);
			write(1, "ra\n", 3);
		}
		i++;
	}
	
	quicksort_a(total, total->curr_a_size / 2);
	quicksort_b(total, total->curr_b_size);
}

void	quicksort_b(t_stack *total, int len)
{
	int	median;
	int	i;
	//int	count;

	i = 0;
	/*printf("got here\n");
	printf("b size is %d\n", total->curr_b_size);
	printf("%d\n", *total->b[total->a_size - total->curr_b_size]);
	printf("%d\n", *total->b[total->a_size - total->curr_b_size + 1]);
	printf("%d\n", *total->b[total->a_size - total->curr_b_size + 2]);
	printf("%d\n", *total->b[total->a_size - total->curr_b_size + 3]);
	printf("%d\n", *total->b[total->a_size - total->curr_b_size + 4]);*/
	printf("B LEN IS %d\n", len);
	if (len < 2)
	{
		if (total->curr_b_size == 2)
			size_two_b(total);
		else if (total->curr_b_size == 3)
			size_three_b(total);
		else if (total->curr_b_size == 4)
			size_four_b(total);
		while(total->curr_b_size)
		{
			pa(total);
			write(1, "pa\n", 3);
		}
		return ;
	}
	median = find_b_median(total, len);
	//printf("median is %d\n", median);
	while (i < len)
	{
		if (*total->b[total->a_size - total->curr_b_size] > median)
		{
			//printf("got here as well!!!\n");
			pa(total);
			write(1, "pa\n", 3);
			/*printf("b size is %d\n", total->curr_b_size);
			i = 0;
			printf("A: \n");
			while (i < total->curr_a_size)
			{
				printf("%d\n", *total->a[i]);
				i++;
			}
			printf("B: \n");
			printf("%d\n", *total->b[total->a_size - total->curr_b_size]);
			printf("%d\n", *total->b[total->a_size - total->curr_b_size + 1]);
			printf("%d\n", *total->b[total->a_size - total->curr_b_size + 2]);
			printf("%d\n", *total->b[total->a_size - total->curr_b_size + 3]);*/
		}
		else
		{
			//printf("got here!!!\n");
			rot(total, 'b', total->b, total->curr_b_size);
			write(1, "rb\n", 3);
		}
		i++;
	}
	
	quicksort_a(total, total->curr_a_size / 2);
	quicksort_b(total, total->curr_b_size / 2);
}