#include <pipex.h>

void	exec(t_vals *vals)
{
	char	*cmd;
	char	**cmd_split;

	cmd_split = ft_split(vals->cmds_argv[vals->num], ' ');
	cmd = ft_strjoin(vals->cmds_path[vals->num], cmd_split[0]);
	if (execve(cmd, cmd_split, vals->env) < 0)
		print_error(0);
}

pid_t	exec_child(t_vals *vals)
{
	pid_t	pid;

	if (pipe(vals->pipe_fd) < 0)
		print_error(0);
	pid = fork();
	if (pid < 0)
		print_error(0);
	if (pid == 0)
	{
		close(vals->pipe_fd[0]);
		dup2(vals->pipe_fd[1], STDOUT_FILENO);
		close(vals->pipe_fd[1]);
		exec(vals);
	}
	else
	{
		close(vals->pipe_fd[1]);
		dup2(vals->pipe_fd[0], STDIN_FILENO);
		close(vals->pipe_fd[0]);
	}
	return (pid);
}

void	pipex(char *infile, char *outfile, t_vals *vals)
{
	int		i;
	int		fd;
	pid_t	pid;

	i = 0;
	while (vals->cmds_argv[i])
		i++;
	fd = open(infile, O_RDONLY);
	if (fd < 0)
		print_error(0);
	printf("fd ->%d\n", fd);
	unlink("/tmp/file");
	printf("fd ->%d\n", fd);
	dup2(fd, STDIN_FILENO);
	close(fd);
	while (vals->cmds_argv[vals->num] && vals->num < i - 1)
	{
		pid = exec_child(vals);
		vals->num += 1;
	}
	check_herefile(infile);
	wait(&pid);
	fd = open(outfile, O_RDWR | O_CREAT | O_TRUNC, 0644);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	exec(vals);
}
