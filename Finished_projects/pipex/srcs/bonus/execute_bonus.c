/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:10:58 by touteiro          #+#    #+#             */
/*   Updated: 2023/01/17 16:28:44 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	execute_command(t_command *cmd, t_env *env)
{
	dup2(cmd->fd_in, STDIN_FILENO);
	if (cmd->next)
		dup2(cmd->fd[1], STDOUT_FILENO);
	else
		dup2(env->files[1], STDOUT_FILENO);
	close(cmd->fd[0]);
	close(cmd->fd[1]);
	execve(cmd->path, cmd->args, env->envp);
	error_handle(cmd->args[0], 2, cmd);
}

void	process_pipe(t_env *env, t_command *cmd)
{
	int			pid;

	cmd->fd_in = env->files[0];
	while (cmd)
	{
		if (pipe(cmd->fd) == -1)
			error_handle("Error creating a pipe", 1, NULL);
		pid = fork();
		if (pid == -1)
			error_handle("Error creating a fork", 1, NULL);
		if (pid == 0)
			execute_command(cmd, env);
		if (cmd->next)
			cmd->next->fd_in = dup(cmd->fd[0]);
		close(cmd->fd[0]);
		close(cmd->fd[1]);
		cmd = cmd->next;
	}
}
