/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:10:58 by touteiro          #+#    #+#             */
/*   Updated: 2023/01/13 21:20:26 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_to_outfile(t_command *commands)
{
	dup2(commands->fd_write, STDOUT_FILENO);
	dup2(commands->fd_read, STDIN_FILENO);
	if (execve(commands->path, commands->args, NULL) == -1)
		exit(printf("Couldn't find command\n"));
}

t_command	*execute_command(t_command *commands)
{
	int		id;
	// int		file;
	int		fd[2];
	// int		i;

	// i = -1;
	if (pipe(fd) == -1)
		exit(printf("Error piping\n"));
	// printf("%d %d\n", fd[0], fd[1]);
	// printf("command is %s, read is %d, write %d\n", commands->args[0], commands->fd_read, commands->fd_write);
	if (!commands->fd_read)
		commands->fd_read = fd[0];
	if (commands->fd_write == 1)
		commands->fd_write = fd[1];
	// printf("command is %s, read is %d, write %d\n", commands->args[0], commands->fd_read, commands->fd_write);
	id = fork();
	if (id == -1)
		exit(printf("Error forking\n"));
	else if (id == 0)
	{
		printf("read  is %d, write is %d\n", commands->fd_read, commands->fd_write);
		dup2(commands->fd_write, STDOUT_FILENO);
		dup2(commands->fd_read, STDIN_FILENO);
		if (execve(commands->path, commands->args, NULL) == -1)
			exit(printf("Couldn't find command\n"));
	}
	else
	{
		int wstatus;
		int	statusCode;
		wait(&wstatus);
		statusCode = WEXITSTATUS(wstatus);
		if (statusCode != 0)
			printf("Failure running %s\n", commands->args[0]);
		commands = commands->next;
		if (commands)
		{
			commands->fd_read = fd[1];
			if (commands->next)
				commands->fd_write = 1;
		}
	}
	return (commands);
}

void	do_actions(t_command *commands)
{
	if (!commands)
		return ;
	commands = execute_command(commands);
	do_actions(commands);
}
