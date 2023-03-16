/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorais- <amorais-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 00:51:30 by touteiro          #+#    #+#             */
/*   Updated: 2023/03/06 11:37:30 by amorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**recursive_split(char *str, char **arr, int words, char c)
{
	char	*new_str;
	int		i;

	i = 0;
	new_str = 0;
	while (str && *str && *str == c)
		str++;
	while (str && str[i] && str[i] != c)
		i++;
	if (i > 0)
		new_str = ft_calloc(i + 1, 1);
	i = 0;
	while (new_str && str && *str && *str != c)
		new_str[i++] = *str++;
	if (new_str)
		arr = recursive_split(str, arr, words + 1, c);
	else
		arr = (char **)malloc(sizeof(char *) * (words + 1));
	if (arr)
		arr[words] = new_str;
	return (arr);
}

char	**ft_split(const char *str, char c)
{
	if (!str)
		return (NULL);
	return (recursive_split((char *)str, NULL, 0, c));
}

/* int	main(void)
{
	int		i = 0;
	char	**split = ft_split("|Some|| ||random|string|||||| !||", '|');

	while (split[i])
	{
		printf("%s\n", split[i]);
		free(split[i]);
		i++;
	}
	free(split);
} */
