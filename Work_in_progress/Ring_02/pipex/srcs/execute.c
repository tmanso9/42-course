/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:10:58 by touteiro          #+#    #+#             */
/*   Updated: 2023/01/13 18:50:16 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_to_outfile(t_files *files, t_command *commands, char *path)
{
	int	file;

	file = open(files->outfile, O_RDWR | O_CREAT, 0777);
	if (file == -1)
		exit(printf("Couldn't access file\n"));
	dup2(file, STDOUT_FILENO);
	close(file);
	if (execve(path, commands->args, NULL) == -1)
		exit(printf("Couldn't find command\n"));
}

t_command	*execute_command(t_files *files, t_command *commands)
{
	char	*path;
	int		id;
	// int		file;
	int		fd[2];
	char	**cmd_full;
	int		i;

	cmd_full = ft_split(commands->args[0], ' ');
	i = -1;
	path = ft_strjoin("/usr/bin/", cmd_full[0]);
	if (pipe(fd) == -1)
		exit(printf("Error piping\n"));
	
	id = fork();
	if (id == -1)
		exit(printf("Error forking\n"));
	else if (id == 0)
	{
		if (!commands->next)
			print_to_outfile(files, commands, path);
		else
		{
			if (execve(path, commands->args, NULL) == -1)
				exit(printf("Couldn't find command\n"));
		}
	}
	else
	{
		int wstatus;
		int	statusCode;
		wait(&wstatus);
		statusCode = WEXITSTATUS(wstatus);
		if (statusCode != 0)
			printf("Failure running %s\n", cmd_full[0]);
	}
	free(path);
	while (cmd_full[++i])
		free(cmd_full[i]);
	free(cmd_full);
	return (commands->next);
}

void	do_actions(t_files *files, t_command *commands)
{
	if (!commands)
		return ;
	commands = execute_command(files, commands);
	do_actions(files, commands);
}
