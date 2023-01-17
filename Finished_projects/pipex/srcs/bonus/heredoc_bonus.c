/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 22:52:41 by touteiro          #+#    #+#             */
/*   Updated: 2023/01/17 17:26:37 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

/* 
* This here_doc processor doesn't work as seamlessly as the terminal native
* redirection because it is not possible to capture key presses directly 
* without the need of pressing enter. The terminal input is buffered by
* default, and without a library to handle it, it's not possible to read 
* the input in real-time.
* Because of this, the read function only recognizes the limiter char
* after enter is pressed.
*/
void	process_heredoc(char **argv, t_env *env)
{
	char	*str;
	char	*lim;

	env->here_doc = 1;
	write(1, "> ", 2);
	env->files[0] = open(env->infile, O_RDWR | O_CREAT, 0666);
	str = get_next_line(0);
	lim = ft_strjoin(argv[2], "\n");
	while (str)
	{
		write(1, "> ", 2);
		if (ft_strchr(str, *lim) && \
			(!ft_strncmp(ft_strchr(str, *lim), lim, ft_strlen(lim))))
			break ;
		ft_putstr_fd(str, env->files[0]);
		free(str);
		str = get_next_line(0);
	}
	if (str)
		free(str);
	free(lim);
	close(env->files[0]);
	env->files[0] = open(env->infile, O_RDONLY);
	env->files[1] = open(env->outfile, O_RDWR | O_CREAT | O_APPEND, 0666);
}
