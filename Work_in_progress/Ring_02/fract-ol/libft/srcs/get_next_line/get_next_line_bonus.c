/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:05:38 by touteiro          #+#    #+#             */
/*   Updated: 2022/11/29 19:47:14 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

char	*update_log(char *line_log)
{
	char	*new_log;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (line_log[i] && line_log[i] != '\n')
		i++;
	if (!line_log[i])
	{
		free(line_log);
		return (NULL);
	}
	new_log = (char *)malloc(sizeof(char) * (ft_strlen(line_log) - i + 1));
	i += 1;
	while (line_log[i])
	{
		new_log[j] = line_log[i];
		j++;
		i++;
	}
	new_log[j] = '\0';
	free(line_log);
	return (new_log);
}

char	*extract_line(char *line_log)
{
	int		i;
	char	*str;

	i = 0;
	if (!line_log[i])
		return (NULL);
	while (line_log[i] && line_log[i] != '\n')
		i++;
	str = ft_calloc(i + 2, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (line_log[i] && line_log[i] != '\n')
	{
		str[i] = line_log[i];
		i++;
	}
	if (line_log[i] && line_log[i] == '\n')
		str[i] = '\n';
	return (str);
}

char	*read_until_nl(int fd, char *line_log)
{
	char	*buff;
	int		f_read;

	f_read = 1;
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	while (f_read > 0 && !ft_strchr_gnl(line_log, '\n'))
	{
		f_read = read(fd, buff, BUFFER_SIZE);
		if (f_read < 0)
		{
			if (line_log && ft_strchr_gnl(line_log, '\0'))
				free (line_log);
			free(buff);
			return (NULL);
		}
		buff[f_read] = 0;
		line_log = ft_strjoin_gnl(line_log, buff);
	}
	free(buff);
	return (line_log);
}

/*
line_log has size of 1024 because linux systems limit
the number of file descriptors that any
one process may open to 1024 per process.
*/
char	*get_next_line(int fd)
{
	char		*str;
	static char	*line_log[1024];

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	if (line_log[fd] && ft_strchr_gnl(line_log[fd], '\n'))
	{
		str = extract_line(line_log[fd]);
		line_log[fd] = update_log(line_log[fd]);
		return (str);
	}
	line_log[fd] = read_until_nl(fd, line_log[fd]);
	if (!line_log[fd])
		return (NULL);
	str = extract_line(line_log[fd]);
	line_log[fd] = update_log(line_log[fd]);
	return (str);
}
