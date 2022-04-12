#include <pipex.h>

void	child_cmd(char *infile, t_vals *vals)
{
	int		fd;
	char	*cmd;
	char	**cmd_split;

	close(vals->pipe_fd[0]);
	fd = open(infile, O_RDONLY);
	if (fd < 0)
		print_error();
	dup2(fd, STDIN_FILENO);
	close(fd);
	close(vals->pipe_fd[0]);
	dup2(vals->pipe_fd[1], STDOUT_FILENO);
	close(vals->pipe_fd[1]);
	cmd_split = ft_split(vals->cmds_argv[vals->num], ' ');
	cmd = ft_strjoin(vals->cmds_path[vals->num], cmd_split[0]);
	if (execve(cmd, cmd_split, vals->env) < 0)
		print_error();
}

void	inter_cmd(t_vals *vals)
{
	char *cmd;
	char **cmd_split;

	cmd_split = ft_split(vals->cmds_argv[vals->num], ' ');
	cmd = ft_strjoin(vals->cmds_path[vals->num], cmd_split[0]);
	// dup2(vals->pipe_fd[1], STDIN_FILENO);
	close(vals->pipe_fd[0]);
	dup2(vals->pipe_fd[1], STDOUT_FILENO);
	close(vals->pipe_fd[1]);
	// close(vals->pipe_fd[1]);
	if (execve(cmd, cmd_split, vals->env) < 0)
		print_error();
	close(vals->pipe_fd[0]);
	dup2(vals->pipe_fd[1], STDIN_FILENO);
	close(vals->pipe_fd[1]);
}
void	parent_cmd(char *outfile, t_vals *vals)
{
	int		fd;
	char	*cmd;
	char	**cmd_split;

	fd = open(outfile, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		print_error();
	cmd_split = ft_split(vals->cmds_argv[vals->num], ' ');
	cmd = ft_strjoin(vals->cmds_path[vals->num], cmd_split[0]);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	if (execve(cmd, cmd_split, vals->env) < 0)
		print_error();
}

void	pipex(char *infile, char *outfile, t_vals *vals)
{
	int		i;
	pid_t	pid;

	i = 0;
	while (vals->cmds_argv[i])
		i++;
	if (pipe(vals->pipe_fd) < 0)
		print_error();
	pid = fork();
	if (pid < 0)
		print_error();
	if (pid == 0)
		child_cmd(infile, vals);
	while (vals->cmds_argv[vals->num] && vals->num < i - 1)
	{
		vals->num += 1;
		close(vals->pipe_fd[1]);
		dup2(vals->pipe_fd[0], STDIN_FILENO);
		close(vals->pipe_fd[0]);
		// ft_bzero(vals->pipe_fd, 2);
		// wait(&pid);
		if (pipe(vals->pipe_fd) < 0)
			print_error();
		pid = fork();
		if (pid < 0)
			print_error();
		if (pid == 0)
			inter_cmd(vals);
	}
	printf("fallo en padre\n");
	parent_cmd(outfile, vals);
}
