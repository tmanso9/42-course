/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:25:55 by touteiro          #+#    #+#             */
/*   Updated: 2023/01/14 12:39:22 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <errno.h>

/* Execute another program */
void	execute_program(char **argv)
{
	char	*path;
	int		id;
	int		file;

	path = ft_strjoin("/usr/bin/", argv[0]);
	// if (access("test2", O_WRONLY) != 0)
	// 	exit(printf("Couldn't access file\n"));
	id = fork();
	if (id == -1)
		exit(printf("Error forking\n"));
	else if (id == 0)
	{
		file = open("test2", O_RDWR | O_CREAT, 0777);
		if (file == -1)
			exit(printf("Couldn't access file\n"));
		dup2(file, STDOUT_FILENO);
		close(file);
		if (execve(path, argv, NULL) == -1)
			exit(printf("Couldn't find command\n"));
	}
	else
	{
		int wstatus;
		int	statusCode;
		wait(&wstatus);
		statusCode = WEXITSTATUS(wstatus);
		if (statusCode == 0)
			printf("Sucess!\n");
		else
			printf("Failure running %s\n", argv[0]);
	}
	free(path);
}

/* 
Sum of array by forking and dividing processing in two
*/
void	second_test_with_pipe(void)
{
	int	arr[] = {1, 2, 3, 200, 4, 1, 2, 8, 20};
	int	fd[2];
	int	id;
	int	start;
	int	end;
	int	sum = 0;

	if (pipe(fd)== -1)
		exit(printf("Error creating the pipe\n"));
	id = fork();
	if (id == -1)
		exit(printf("Error forking\n"));
	else if (id == 0)
	{
		start = 0;
		end = (sizeof(arr) / sizeof(int)) / 2;
	}
	else
	{
		start = (sizeof(arr) / sizeof(int)) / 2;
		end = sizeof(arr) / sizeof(int);
	}
	while (start < end)
	{
		sum += arr[start];
		start++;
	}
	printf("partial sum of id %d is %d\n", id, sum);
	if (id == 0)
	{
		close(fd[0]);
		if (write(fd[1], &sum, sizeof(sum)) == -1)
			exit(printf("Error writing\n"));
		close(fd[1]);
	}
	else
	{
		close(fd[1]);
		int	y;
		if (read(fd[0], &y, sizeof(int)) == -1)
			exit(printf("Error reading\n"));
		close(fd[0]);
		sum += y;
		printf("total sum is %d\n", sum);
		wait(NULL);
	}
}

/* 
Writing a char in child process and reading in parent process
*/
void	first_test_with_pipe(void)
{
	int	fd[2];
	// fd[0] = open("test1", O_RDONLY);
	// fd[1] = open("test2", O_RDWR);
	if (pipe(fd) == -1)
		printf("error opening the pipe\n");
	int	id = fork();
	if (id == 0)
	{
		close(fd[0]);
		char	x;
		printf("input a character: ");
		scanf("%c", &x);
		if (write(fd[1], &x, sizeof(char)) == -1)
			printf("error occured when writing");
		close(fd[1]);
	}
	else
	{
		close(fd[1]);
		char	y;
		if (read(fd[0], &y, sizeof(char)) == -1)
			printf("error occured when reading");
		close(fd[0]);
		printf("Got from child process %c\n", y);
	}
}

/*
Forking several times and waiting for all children and grandchildren
*/
void	forking_several_times(void)
{
	int	id1 = fork();
	int	id2 = fork();

	while (wait(NULL) != -1 || errno != ECHILD)
		;
	if (id1 == 0)
	{
		if (id2 == 0)
			printf("We are process y\n");
		else
			printf("We are process x\n");
	}
	else
	{
		if (id2 == 0)
			printf("We are process z\n");
		else
			printf("We are tHe MoThEr\n");
	}
}

void	fork_print_ten_numbers(void)
{
	int	id;

	id = fork();
	// Print numbers from 1 to 10
	int	n;
	int	i;
	if (id == 0)
		n = 1;
	else
		n = 6;
	i = n - 1;
	waitpid(0, 0, 0);
	while (++i < n + 5)
		ft_printf("%d ", i);
	if (id != 0)
		ft_printf("\n");
}

int	main(int argc, char **argv, char **env_path)
{
	// fork_print_ten_numbers();
	
	/* Forking several times and waiting for all children and grandchildren */
	// forking_several_times();
	
	/* Writing a char in child process and reading in parent process */
	// first_test_with_pipe();
	
	/* 	Sum of array by forking and dividing processing in two*/
	// second_test_with_pipe();

	// if (argc > 1)
	// 	execute_program(&argv[1]);
	// int	i = 0;
	static t_env		env;
	static t_command	*commands;
	if (argc > 1)
	{

		commands = ft_calloc(1, sizeof(t_command));
		if (!commands)
			exit(0);
		parse_args(argc, argv, &files, commands);
		temp = commands;
		find_path(commands, env_path);
		commands = temp;
		while (commands)
		{
			printf("%s\n", commands->path);
			commands = commands->next;
		}
		commands = temp;
		// printf("Number of commands: %d\n", ft_lstsize((t_list *)commands));
		do_actions(commands);
		free_all(files, temp);
	}
}
