/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:25:55 by touteiro          #+#    #+#             */
/*   Updated: 2023/01/15 02:26:27 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * The main function parses the arguments, creates the linked list of commands,
 * and then calls the process_pipe function to execute the commands
 * 
 * @param env_path the environment variables
 */
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
	exit (EXIT_SUCCESS);
}
