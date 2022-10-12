/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 00:51:30 by touteiro          #+#    #+#             */
/*   Updated: 2022/10/12 10:36:34 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char	*str_alloc(char **split, int *i, int *j, const char *s)
{
	split[*j] = (char *)malloc(sizeof(char) * (*i + 1));
	if (!split[*j])
		return (NULL);
	ft_strlcpy(split[*j], (char *)s, (*i) + 1);
	return (s);
}

static int	count_words(const char *s, char c, int i)
{
	int	words;

	words = 0;
	if (s == NULL)
		return (words);
	if (s[i] && s[i] != c)
		words = 1;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] && s[i + 1] != c)
			words++;
		i++;
	}
	return (words);
}

static char	**check_str(const char *s, int words, char c, char **split)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < words && s[i])
	{
		while (s[i] == c)
			s++;
		while (s[i] != c && s[i])
			i++;
		if (i != 0)
		{
			s = str_alloc(split, &i, &j, s) + i + 1;
			i = 0;
			j++;
		}
	}
	return (split);
}

char	**ft_split(const char *s, char c)
{
	int		i;
	int		words;
	char	**split;

	i = 0;
	if (s == NULL)
		return (NULL);
	words = count_words(s, c, i);
	split = (char **)malloc(sizeof(char *) * (words + 1));
	if (!split)
		return (NULL);
	split = check_str(s, words, c, split);
	split[words] = NULL;
	return (split);
}

/*
int	main(int argc, char **argv)
{
	int		i = 0;
	(void)argc;
	(void)argv;
	char	**split = ft_split("|Some|| ||random|string|||||| !||", '|');
	while (split[i])
	{
		printf("%s\n", split[i]);
		i++;
	}
}
*/