/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:28:41 by touteiro          #+#    #+#             */
/*   Updated: 2023/01/14 19:18:49 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	is_path_line(char **paths)
{
	int	i;

	i = -1;
	while (paths[++i])
	{
		if (ft_strchr(paths[i], 'P') == paths[i] && \
			ft_strchr(paths[i], 'A') == paths[i] + 1 && \
			ft_strchr(paths[i], 'T') == paths[i] + 2 && \
			ft_strchr(paths[i], 'H') == paths[i] + 3)
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
	path_line = env_path[is_path_line(env_path)];
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

	i = 1;
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

void	parse_env(int argc, char **argv, t_env *env)
{
	env->infile = argv[1];
	env->outfile = argv[argc - 1];
	env->files[0] = open(env->infile, O_RDONLY);
	if (env->files[0] < 0)
		error_handle(env->infile, 0);
	env->files[1] = open(env->outfile, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (env->files[1] < 0)
		error_handle(env->outfile, 0);
}

void	parse_args(int argc, char **argv, t_env *env, t_command **commands)
{
	parse_env(argc, argv, env);
	env->cmds = parse_cmds(commands, argv, env);
}
