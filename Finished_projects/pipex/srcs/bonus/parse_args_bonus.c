/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:28:41 by touteiro          #+#    #+#             */
/*   Updated: 2023/01/17 17:26:29 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	is_path_line(char **paths)
{
	int	i;

	i = -1;
	while (paths[++i])
	{
		if (ft_strncmp(paths[i], "PATH", 4) == 0)
			return (i);
	}
	return (0);
}

char	*find_path(char **env_path, char *cmd)
{
	char	**paths;
	char	*path_line;
	char	*intermediate;
	char	*final_path;
	int		i;

	i = -1;
	path_line = env_path[is_path_line(env_path)] + 5;
	paths = ft_split(path_line, ':');
	while (paths[++i])
	{
		intermediate = ft_strjoin(paths[i], "/");
		final_path = ft_strjoin(intermediate, cmd);
		if (access(final_path, F_OK) == 0)
		{
			free (intermediate);
			free_arr((void *)paths);
			return (final_path);
		}
		free (intermediate);
		free (final_path);
	}
	free_arr((void *)paths);
	return (ft_strdup(cmd));
}

t_command	**parse_cmds(t_command **head, char **argv, t_env *env)
{
	int			i;
	t_command	*temp;
	t_command	*end;

	i = 1 + env->here_doc;
	end = NULL;
	while (argv[++i + 1])
	{
		temp = ft_calloc(1, sizeof(t_command));
		if (!temp)
			return (NULL);
		temp->args = ft_split(argv[i], ' ');
		temp->path = find_path(env->envp, temp->args[0]);
		temp->next = NULL;
		if (!(*head))
			*head = temp;
		if (end)
			end->next = temp;
		end = temp;
	}
	return (head);
}

/**
 * It opens the input and output files, and sets the here_doc flag
 */
void	parse_env(int argc, char **argv, t_env *env)
{
	env->infile = argv[1];
	env->outfile = argv[argc - 1];
	if (!(ft_strncmp(env->infile, "here_doc", 8)))
		process_heredoc(argv, env);
	else
	{
		env->here_doc = 0;
		env->files[0] = open(env->infile, O_RDONLY);
		env->files[1] = open(env->outfile, O_RDWR | O_CREAT | O_TRUNC, 0666);
	}
	if (env->files[0] < 0)
		error_handle(env->infile, 0, NULL);
	if (env->files[1] < 0)
		error_handle(env->outfile, 0, NULL);
}

void	parse_args(int argc, char **argv, t_env *env, t_command **commands)
{
	parse_env(argc, argv, env);
	env->cmds = parse_cmds(commands, argv, env);
}
