/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 12:34:56 by touteiro          #+#    #+#             */
/*   Updated: 2022/11/18 18:59:08 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"
#include "../libft/libft.h"

int	multi_args(int argc, char **argv, t_list *a)
{
	int		i;
	int		*num;
	t_list	first;

	i = 0;
	//first = 0;
	num = (int *)malloc(sizeof(int));
	while (argc > ++i)
	{
		if (argv[i][0] == '-' && ft_strlen(argv[i]) > 10 && \
			ft_strncmp("-2147483648", argv[i], 12) < 0)
		{
			printf("got here, argv[%d] is %s\n", i, argv[i]);
			return (0);
		}
		else if ((ft_strlen(argv[i]) > 9 &&\
			ft_strncmp("2147483647", argv[i], 11) < 0) ||\
			(argv[i][0] != '-' && ft_strlen(argv[i]) > 10))
		{
			printf("got here, argv[%d] is %s\n", i, argv[i]);
			return (0);
		}
	}
	a = (t_list *)malloc(sizeof(t_list) * argc);
	//printf("a is %p, first is %p\n", a, first);
	/*a = ft_lstnew(num);
	first = *a;
	a = a->next;*/
	//printf("a is %p, first is %p\n", a, first);
	i = 0;
	while (argc > ++i)
	{
		*num = ft_atoi(argv[i]);
		//printf("a is %p\n", a);
		if (!a)
		{
			a = ft_lstnew(num);
			first = *a;
		}
		else
		{
			a->next = ft_lstnew(num);
			a = a->next;
		}
		//printf("a is %p\n", a);
		//printf("%d\n", *(int *)a->content);
		
	}
	printf("first content is %d\n", *(int *)first.content);
	//printf("a is %p, first is %p\n", a, first);
	a = &first;
	//printf("a is %p, first is %p\n", a, first);
	while (a)
	{
		printf("got in\n");
		printf("%d\n", *(int *)a->content);
		a = a->next;
	}
	free(num);
	return (1);
}

int	check_args(int argc, char **argv, t_list *a)
{
	int		i;
	char	**str;

	i = 0;
	str = NULL;
	if (argc < 2)
		return (0);
	else if (argc > 2)
	{
		if (!multi_args(argc, argv, a))
			return (0);
	}
	/*else
	{
		str = ft_split(argv[1], ' ');
		while (str[i])
			i++;
		arr = ft_calloc(i + 1, sizeof(int));
		i = -1;
		while (str[++i])
		{
			arr[i] = ft_atoi(str[i]);
			free(str[i]);
		}
		free(str);
	}
	i = 0;
	while (arr[i])
	{
		printf("%d\n", arr[i]);
		i++;
	}
	free(arr);*/
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		*arr;

	arr = NULL;
	a = NULL;
	b = NULL;
	if (check_args(argc, argv, a) <= 0)
	{
		//Replace printf
		printf("Incorrect arguments!\n");
		return (0);
	}
	else
	{
		printf("args ok\n");
	}
	free(a);
	free(b);
}
