/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:05:38 by touteiro          #+#    #+#             */
/*   Updated: 2022/10/31 11:36:01 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		i++;
		j++;
	}
	new_log[j] = '\0';
	free(line_log);
	return (new_log);
}

/*
This function allocates the mem to i + 2 and all mem values are
initialized at 0.
This makes it so the last byte is a null byte, and so we don't
need to make it so after copying the text to the string.
*/
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
	while (f_read > 0 && !ft_strchr(line_log, '\n'))
	{
		f_read = read(fd, buff, BUFFER_SIZE);
		if (f_read < 0)
		{
			if (line_log && ft_strchr(line_log, '\0'))
				free (line_log);
			free(buff);
			return (NULL);
		}
		buff[f_read] = 0;
		line_log = ft_strjoin(line_log, buff);
	}
	free(buff);
	return (line_log);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	*line_log;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (line_log && (ft_strchr(line_log, '\n')))
	{
		str = extract_line(line_log);
		line_log = update_log(line_log);
		return (str);
	}
	line_log = read_until_nl(fd, line_log);
	if (!line_log)
		return (NULL);
	str = extract_line(line_log);
	line_log = update_log(line_log);
	return (str);
}
