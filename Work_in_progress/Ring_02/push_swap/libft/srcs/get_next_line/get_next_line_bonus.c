/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:05:38 by touteiro          #+#    #+#             */
/*   Updated: 2022/12/24 01:30:47 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			i;
	int			j;
	int			flag;

	if (read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	flag = 0;
	while (!flag && (buffer[0] || (read(fd, buffer, BUFFER_SIZE) > 0)))
	{
		line = strjoin_gnl(line, buffer);
		i = 0;
		j = 0;
		while (buffer[i])
		{
			if (flag)
				buffer[j++] = buffer[i];
			if (buffer[i] == '\n')
				flag = 1;
			buffer[i++] = 0;
		}
	}
	return (line);
}
