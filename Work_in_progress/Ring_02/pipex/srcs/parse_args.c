/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:28:41 by touteiro          #+#    #+#             */
/*   Updated: 2023/01/13 21:11:10 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	line_is_path(int i, char **env)
{
	if (ft_strchr(env[i], 'P') == env[i] && \
		ft_strchr(env[i], 'A') == env[i] + 1 && \
		ft_strchr(env[i], 'T') == env[i] + 2 && \
		ft_strchr(env[i], 'H') == env[i] + 3)
		return (1);
	return (0);
}

void	find_path(t_command *commands, char **env)
{
	char	*path_line;
	char	*intermediate;
	char	**paths;
	int		i;

	i = -1;
	while (env[++i])
		if (line_is_path(i, env))
			path_line = ft_strdup(env[i] + 5);
	paths = ft_split(path_line, ':');
	free(path_line);
	i = -1;
	while (commands)
	{
		while (paths[++i])
		{
			intermediate = ft_strjoin(paths[i], "/");
			path_line = ft_strjoin(intermediate, commands->args[0]);
			if (!access(path_line, F_OK))
			{
				commands->path = ft_strdup(path_line);
				free (intermediate);
				free (path_line);
				break ;
			}
			free (intermediate);
			free (path_line);
		}
		i = -1;
		if (!commands->path)
			commands->path = ft_strdup(commands->args[0]);
		i = -1;
		commands = commands->next;
	}
	i = -1;
	while (paths[++i])
		free (paths[i]);
	free (paths);
}

void	parse_args(int argc, char **argv, t_files *files, t_command *commands)
{
	int			i;
	t_command	*first;

	i = 1;
	first = commands;
	files->infile = ft_strdup(argv[1]);
	files->outfile = ft_strdup(argv[argc - 1]);
	while (++i < argc - 1)
	{
		commands->args = ft_split(argv[i], ' ');
		if (i == 2)
			commands->fd_read = open(files->infile, O_RDONLY);
		else
			commands->fd_read = 0;
		if (i != argc - 2)
		{
			commands->fd_write = 1;
			commands->next = ft_calloc(1, sizeof(t_command));
			commands = commands->next;
		}
		else
		{
			commands->fd_write = open(files->outfile, O_WRONLY | O_CREAT, 0777);
			// printf("ORIGINAL WRITE %d\n", commands->fd_write);
			commands->next = NULL;
		}
	}
	commands = first;
}
