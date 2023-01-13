/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:02:46 by touteiro          #+#    #+#             */
/*   Updated: 2023/01/13 19:29:12 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_files(t_files files)
{
	// printf("%s %s\n", files.infile, files.outfile);
	free(files.infile);
	free(files.outfile);
}

void	free_commands(t_command *commands)
{
	t_command	*temp;
	int			i;

	close(commands->fd_read);
	while (commands)
	{
		i = -1;
		while(commands->args[++i])
			free(commands->args[i]);
		// printf("%s\n", commands->args[0]);
		free(commands->args);
		free(commands->path);
		temp = commands;
		commands = commands->next;
		free(temp);
	}
}

void	free_all(t_files files, t_command *commands)
{
	free_files(files);
	free_commands(commands);
}
