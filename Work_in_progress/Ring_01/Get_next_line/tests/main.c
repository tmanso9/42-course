/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 10:29:03 by touteiro          #+#    #+#             */
/*   Updated: 2022/11/02 12:32:41 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "get_next_line_bonus.h"

int	main(void)
{
	char	*str;
	int	fd = open("/etc/crontab", O_RDONLY);
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
	printf("%s", str);
	free(str);
	close(fd);
}
