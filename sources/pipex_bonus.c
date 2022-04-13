#include <pipex.h>

void ejecutar(t_vals *vals)
{
	char	*cmd;
	char	**cmd_split;

	printf("%d\n", vals->num);
	cmd_split = ft_split(vals->cmds_argv[vals->num], ' ');
	cmd = ft_strjoin(vals->cmds_path[vals->num], cmd_split[0]);
	if(execve(cmd, cmd_split, vals->env) < 0)
		print_error();
}

void pipex(char *infile, char *outfile, t_vals *vals)
{
	int		i;
	int		fd;
	pid_t	pid;

	i = 0;
	while (vals->cmds_argv[i])
		i++;
	fd = open(infile, O_RDONLY);
	if(fd  < 0)
		print_error();
	dup2(fd , STDIN_FILENO);
	close(fd);
	while(vals->cmds_argv[vals->num] && vals->num < i - 1)
	{
		if (pipe(vals->pipe_fd) < 0)
			print_error();
		pid = fork();
		if (pid < 0)
			print_error();
		if (pid == 0)
		{
			close(vals->pipe_fd[0]);
			dup2(vals->pipe_fd[1], STDOUT_FILENO);
			close(vals->pipe_fd[1]);
			ejecutar(vals);
		}
		else
		{
			close(vals->pipe_fd[1]);
			dup2(vals->pipe_fd[0], STDIN_FILENO);
			close(vals->pipe_fd[0]);
		}
		vals->num += 1;
	}
	wait(&pid);
	fd = open(outfile, O_RDWR | O_CREAT | O_TRUNC, 0644);;
	dup2(fd, STDOUT_FILENO);
	close(fd);
	ejecutar(vals);
}

