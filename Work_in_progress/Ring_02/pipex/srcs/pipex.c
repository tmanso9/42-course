/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:25:55 by touteiro          #+#    #+#             */
/*   Updated: 2023/01/14 19:17:52 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env_path)
{
	static t_env		env;
	static t_command	*commands;
	static t_command	*head;
	int					i;

	if (argc != 5)
		error_handle("", -1);
	env.envp = env_path;
	parse_args(argc, argv, &env, &commands);
	head = *env.cmds;
	process_pipe(&env, commands);
	i = 1;
	while (++i < argc - 2)
		waitpid(-1, NULL, 0);
	final_free(head);
	close(env.files[0]);
	close(env.files[1]);
	exit (0);
}
