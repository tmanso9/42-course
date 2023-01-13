/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:26:23 by touteiro          #+#    #+#             */
/*   Updated: 2023/01/13 19:06:25 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

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
	int					fd_read;
	int					fd_write;
	struct s_command	*next;
}	t_command;

typedef struct s_files
{
	char	*infile;
	char	*outfile;
}	t_files;

void	parse_args(int argc, char **argv, t_files *files, t_command *commands);
void	find_path(t_command *commands, char **env);
void	free_all(t_files files, t_command *commands);
void	do_actions(t_files *files, t_command *commands);

#endif