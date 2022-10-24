/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:19:56 by touteiro          #+#    #+#             */
/*   Updated: 2022/10/17 14:34:35 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	test_ft_isalpha(void);
void	test_ft_isdigit(void);
void	test_ft_isalnum(void);
void	test_ft_isascii(void);
void	test_ft_isprint(void);
void	test_ft_strlen(void);
void	test_ft_memset(void);
void	test_ft_bzero(void);
void	test_ft_memcpy(void);

void	all_tests(void)
{
	printf("\n");
	test_ft_isalpha();
	printf("\n");
	printf("\n");
	test_ft_isdigit();
	printf("\n");
	printf("\n");
	test_ft_isalnum();
	printf("\n");
	printf("\n");
	test_ft_isascii();
	printf("\n");
	printf("\n");
	test_ft_isprint();
	printf("\n");
	printf("\n");
	test_ft_strlen();
	printf("\n\n");
	test_ft_memset();
	printf("\n\n");
	test_ft_bzero();
	printf("\n\n");
	test_ft_memcpy();
	printf("\n\n");
}
void	f(unsigned int n, char *c)
{
	*c = *c + n;
}

void	print(void *content)
{
	printf("%s\n", (char *)content);
}

void	ft_print_result(char const *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

void	ft_print_int_result(int n)
{
	if (n)
		write(1, "1", 1);
	else
		write(1, "0", 1);
}

int	main(int argc, char **argv)
{
	int	i = 1;
	
	if (argc >= 1)
	{
		if (argc == 1)
		{
			all_tests();
			return (0);
		}
		while (i < argc)
		{
			if (strcmp(argv[i], "isalpha") == 0)
			{
				printf("\n");
				test_ft_isalpha();
				printf("\n");
			}
			if (strcmp(argv[i], "isdigit") == 0)
			{
				printf("\n");
				test_ft_isdigit();
				printf("\n");
			}
			if (strcmp(argv[i], "isalnum") == 0)
			{
				printf("\n");
				test_ft_isalnum();
				printf("\n");
			}
			if (strcmp(argv[i], "isascii") == 0)
			{
				printf("\n");
				test_ft_isascii();
				printf("\n");
			}
			if (strcmp(argv[i], "isprint") == 0)
			{
				printf("\n");
				test_ft_isprint();
				printf("\n");
			}
			if (strcmp(argv[i], "strlen") == 0)
			{
				printf("\n");
				test_ft_strlen();
				printf("\n");
			}
			if (strcmp(argv[i], "memset") == 0)
			{
				printf("\n");
				test_ft_memset();
				printf("\n");
			}
			if (strcmp(argv[i], "bzero") == 0)
			{
				printf("\n");
				test_ft_bzero();
				printf("\n");
			}
			if (strcmp(argv[i], "memcpy") == 0)
			{
				printf("\n");
				test_ft_memcpy();
				printf("\n");
			}
			i++;
		}
	}

	return(0);
	//char	*str2;
	//char	c = 'a';
	//int	i = 0;

	if (1)
	{

		
	//	ft_memcpy(str2, str, 3);
	//	ft_memmove(str+3, str, 4);
	//	printf("%d\n", (int)ft_strlcpy(str2, str, 3));
	//	printf("%d\n", (int)ft_strlcat(str2, str, 9));
	//	printf("%s\n", str);
	//	printf("%s\n", str2);
	/*	while (str[i])
		{
			printf("%c", ft_tolower(str[i]));
			i++;
		}
		printf("\n");
	*/
		// char	str2[] = "teste";
		// printf("%s\n", strrchr(str2, 1024));
		// printf("%s\n", ft_strrchr(str2, 1024));
	//	char *str;
	//	if (!(str = ft_strrchr(str2, 's')))
	//		ft_print_result("NULL");
	//	else
	//		ft_print_result(str);
	//	printf("%d\n", strcmp("", ft_strrchr("", '\0')));
	//	printf("str1: %s\nstr2: %s\ncomp: %d\n", str, str2, ft_strncmp(str, str2, 6));
	//	printf("%s\n", (char *)ft_memchr(str, c, 5));
	//	int tab[7] = {-49, 49, 1, -1, 0, -2, 2};
	//	printf("%s\n", (char *)ft_memchr(tab, -1, 7));
	//	printf("%s\n", (char *)memchr(tab, -1, 7));
	//	printf("%d\n", strcmp((char *)ft_memchr(tab, -1, 7), (char *)memchr(tab, -1, 7)));
	//	printf("%s\n", ft_strnstr(str, str2, 3));
	//	char haystack[30] = "aaabcabcd";
	//	printf("%s\n", haystack + 5);
	//	printf("%p\n", str);
	//	str3 = ft_strnstr(haystack, str2, 9);
	//	printf("%s\n", str3);
	//	if (str3 == NULL)
	//		printf("str3 is null\n");
	//	printf("%p\n", str);
		// printf("%d\n", ft_atoi("-06050"));
		// printf("%d\n", atoi("-06050"));
	//	str2 = ft_substr("1", 42, 42000000);
	//	printf("%s\n", ft_substr("hola", 4, 1));
	//	printf("%zu %lu\n%s\n", malloc_size(str2), (ft_strlen("tripouille") + 1), str2);
	//	printf("%s\n", ft_strjoin(str, str2));
	// char **tabstr;
	// int	i = 0;
	// if (!(tabstr = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse", ' ')))
	// 		ft_print_result("NULL");
	// 	else
	// 	{
	// 		while (tabstr[i] != NULL)
	// 		{
	// 			ft_print_result(tabstr[i]);
	// 			printf("\n");
	// 			i++;
	// 		}
	// 	}
	//	printf("%s\n", ft_split("hello!", ' ')[0]);
	//	printf("%s\n", ft_strtrim(str, str2));
	//	printf("%s\n", ft_itoa(INT_MIN));
	//	printf("%s\n", ft_strmapi(str, &f));
	//	ft_striteri(str, &f);
	//	printf("%s\n", str);
	//	ft_putchar_fd(str[0], 1);
	//	ft_putstr_fd(str, 1);
	//	ft_putendl_fd(str, 1);
	//	ft_putnbr_fd(-65438, 1);
	//	t_list	*list;
	//	char	*str = "test";
	//	list = ft_lstnew((void *)str);
	//	list->next = ft_lstnew((void *)str);
	//	list->next->next = ft_lstnew((void *)"teste final");		
	//	printf("%d\n", ft_lstsize(list));
	/*	while (list)
		{
			printf("%s\n", (char *)list->content);
			list = list->next;
		}*/
	//	list = ft_lstlast(list);
	//	printf("%s\n", (char *)list->content);
	//	ft_lstiter(list, &print);
	//	printf("%zu\n", SIZE_MAX);
	}
}
