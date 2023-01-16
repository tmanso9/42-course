int		id;
	// int		file;
	int		fd[2];
	// int		i;

	// i = -1;
	if (pipe(fd) == -1)
		exit(printf("Error piping\n"));
	// printf("%d %d\n", fd[0], fd[1]);
	// printf("command is %s, read is %d, write %d\n", commands->args[0], commands->fd_read, commands->fd_write);
	if (!commands->fd_read)
		commands->fd_read = fd[0];
	if (commands->fd_write == 1)
		commands->fd_write = fd[1];
	// printf("command is %s, read is %d, write %d\n", commands->args[0], commands->fd_read, commands->fd_write);
	id = fork();
	if (id == -1)
		exit(printf("Error forking\n"));
	else if (id == 0)
	{
		// printf("read  is %d, write is %d\n", commands->fd_read, commands->fd_write);
		dup2(commands->fd_write, STDOUT_FILENO);
		dup2(commands->fd_read, STDIN_FILENO);
		// close(commands->fd_read);
		// close(commands->fd_write);
		if (execve(commands->path, commands->args, NULL) == -1)
			exit(printf("Couldn't find command\n"));
	}
	else
	{
		int wstatus;
		int	statusCode;
		wait(&wstatus);
		statusCode = WEXITSTATUS(wstatus);
		printf("%d\n", statusCode);
		if (statusCode > 1)
			printf("Failure running %s\n", commands->args[0]);
		close(fd[1]);
		dup2(commands->fd_write, STDOUT_FILENO);
		close(commands->fd_write);
		close(fd[0]);
		commands = commands->next;
		if (commands)
		{
			commands->fd_read = fd[1];
			if (commands->next)
				commands->fd_write = 1;
		}
	}
	return (commands);
