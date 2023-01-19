/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:43:43 by touteiro          #+#    #+#             */
/*   Updated: 2023/01/19 19:31:34 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*temp;
	int			i;

	i = 0;
	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	if (read(fd, NULL, 0) < 0)
	{
		while (buffer[fd][i])
			buffer[fd][i++] = 0;
		return (NULL);
	}
	temp = NULL;
	while (buffer[fd][0] || read(fd, buffer[fd], BUFFER_SIZE) > 0)
	{
		temp = ft_join(temp, buffer[fd]);
		if (ft_check(buffer[fd]))
			break ;
	}
	return (temp);
}

/* int	main(void)
{
	char	*str;
	int	fd = open("variable_nls.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("Buffer size: %d\n", BUFFER_SIZE);
	int i = 1;
	while (str)
	{
		printf("Iteration %d: %s", i, str);
		i++;
		free(str);
		str = get_next_line(fd);
	}
	printf("\nIteration %d: %s", i, str);
	free(str);
	close(fd);
} */
