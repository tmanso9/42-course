/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:26:23 by touteiro          #+#    #+#             */
/*   Updated: 2023/01/15 00:52:24 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libft/incs/libft.h"
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
	int			here_doc;
	int			files[2];
	char		**envp;
	t_command	**cmds;
}	t_env;

void	parse_args(int argc, char **argv, t_env *env, t_command **commands);
void	process_heredoc(char **argv, t_env *env);
void	process_pipe(t_env *env, t_command *cmd);
void	error_handle(char *message, int id);
void	free_arr(void **arr);
void	final_free(t_command *commands);

#endif