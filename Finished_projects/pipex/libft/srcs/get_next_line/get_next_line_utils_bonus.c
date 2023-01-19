/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:20:08 by touteiro          #+#    #+#             */
/*   Updated: 2023/01/19 19:31:41 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check(char *buffer)
{
	int	i;
	int	j;
	int	new_line;

	i = 0;
	j = 0;
	new_line = 0;
	while (buffer[i])
	{
		if (new_line)
			buffer[j++] = buffer[i];
		if (buffer[i] == '\n')
			new_line = 1;
		buffer[i++] = 0;
	}
	return (new_line);
}

static int	special_strlen(char *str)
{
	int	size;

	size = 0;
	if (!str)
		return (0);
	while (str[size] && str[size] != '\n')
		size++;
	if (str[size] == '\n')
		size++;
	return (size);
}

char	*ft_join(char *temp, char *buffer)
{
	int		i;
	int		j;
	char	*aux;

	aux = malloc(special_strlen(temp) + special_strlen(buffer) + 1);
	if (!aux)
		return (NULL);
	i = 0;
	j = 0;
	while (temp && temp[i])
		aux[j++] = temp[i++];
	free (temp);
	i = 0;
	while (buffer && buffer[i])
	{
		aux[j++] = buffer[i];
		if (buffer[i++] == '\n')
			break ;
	}
	aux[j] = 0;
	return (aux);
}
