/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:02:46 by touteiro          #+#    #+#             */
/*   Updated: 2023/01/16 17:44:22 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_handle(char *message, int id, t_command *cmd)
{
	if (id == -1)
	{
		ft_putendl_fd("Incorrect number of arguments.", 2);
		ft_putendl_fd("\nUsage: ./pipex \"infile\" \"cmd1\" \"cmd2\" \"outfile\"", 2);
	}
	else if (id == 0)
		perror(message);
	else if (id == 1)
		ft_putendl_fd(message, 2);
	else if (id == 2)
	{
		ft_putstr_fd("Error executing ", 2);
		ft_putendl_fd(message, 2);
		final_free(cmd);
	}
	exit (EXIT_FAILURE);
}

void	free_arr(void **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free (arr[i]);
	free (arr);
}

void	final_free(t_command *commands)
{
	t_command	*temp;

	while (commands)
	{
		free_arr((void *)commands->args);
		free(commands->path);
		temp = commands;
		commands = commands->next;
		free(temp);
	}
}

void	process_random(t_env *env)
{
	char	input[1];
	int		fd;
	int		bytes;

	env->random = 1;
	fd = open(env->infile, O_RDONLY);
	env->infile = ".temp";
	env->files[0] = open(env->infile, O_RDWR | O_CREAT, 0666);
	bytes = 10000;
	while (bytes)
	{
		read(fd, input, 1);
		write(env->files[0], input, 1);
		bytes--;
	}
	close(fd);
	close(env->files[0]);
	env->files[0] = open(env->infile, O_RDONLY);
	env->files[1] = open(env->outfile, O_RDWR | O_CREAT | O_TRUNC, 0666);
}

void	unlink_files(t_env env)
{
	if (env.random)
		unlink(".temp");
}
