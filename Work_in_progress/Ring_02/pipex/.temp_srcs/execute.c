/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:10:58 by touteiro          #+#    #+#             */
/*   Updated: 2023/01/14 12:29:33 by touteiro         ###   ########.fr       */
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
	int	id;

	
}

void	do_actions(t_command *commands)
{
	if (!commands)
		return ;
	// printf("read  is %d, write is %d\n", commands->fd_read, commands->fd_write);
	commands = execute_command(commands);
	// printf("read  is %d, write is %d\n", commands->fd_read, commands->fd_write);
	do_actions(commands);
}
