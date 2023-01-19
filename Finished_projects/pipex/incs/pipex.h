/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:26:23 by touteiro          #+#    #+#             */
/*   Updated: 2023/01/19 19:51:40 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_command
{
	char				**args;
	char				*path;
	int					fd_in;
	int					fd[2];
	struct s_command	*next;
}	t_command;

typedef struct s_env
{
	char		*infile;
	char		*outfile;
	int			files[2];
	char		**envp;
	t_command	**cmds;
}	t_env;

void	parse_args(int argc, char **argv, t_env *env, t_command **commands);
void	process_pipe(t_env *env, t_command *cmd);
void	error_handle(char *message, int id, t_command *cmd);
void	unlink_files(t_env env);
void	free_arr(void **arr);
void	final_free(t_command *commands);

#endif