/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 22:52:41 by touteiro          #+#    #+#             */
/*   Updated: 2023/01/15 01:22:12 by touteiro         ###   ########.fr       */
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
	char	input[1];

	env->here_doc = 1;
	write(1, "> ", 2);
	env->files[0] = open(env->infile, O_RDWR | O_CREAT, 0666);
	while (1)
	{
		read(0, input, 1);
		if (input[0] == *argv[2])
			break ;
		write(env->files[0], input, 1);
		if (input[0] == '\n')
			write(1, "> ", 2);
	}
	close(env->files[0]);
	env->files[0] = open(env->infile, O_RDONLY);
	env->files[1] = open(env->outfile, O_RDWR | O_CREAT | O_APPEND, 0666);
}
