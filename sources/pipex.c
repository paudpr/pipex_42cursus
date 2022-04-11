#include <pipex.h>

void child_cmd(char *infile, t_vals *vals)
{
	int		fd;
	char	*cmd;
	char	**cmd_split;

	close(vals->pipe_fd[0]);
	fd = open(infile, O_RDONLY);
	if(fd < 0)
		print_error();
	dup2(fd, STDIN_FILENO);
	close(fd);
	dup2(vals->pipe_fd[1], STDOUT_FILENO);
	close(vals->pipe_fd[1]);
	//cambiar iteradores de cmds_path y argv. también en el split
	cmd_split = ft_split(vals->cmds_argv[vals->num], ' ');
	cmd = ft_strjoin(vals->cmds_path[vals->num], cmd_split[0]);
	if (execve(cmd, cmd_split, vals->env) < 0)
			print_error();
	ft_free_double(cmd_split);
}

void parent_cmd(char *outfile, t_vals *vals)
{
	int fd;
	char *cmd;
	char **cmd_split;
	

	fd = open(outfile, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		print_error();
	dup2(fd, STDOUT_FILENO);
	close(fd);
	//cambiar iteradores de cmds_path y argv. también en el split
	cmd_split = ft_split(vals->cmds_argv[vals->num], ' ');
	cmd = ft_strjoin(vals->cmds_path[vals->num], cmd_split[0]);
	if(execve(cmd, cmd_split, vals->env))
		print_error();
	ft_free_double(cmd_split);
}

void pipex(char *infile, char *outfile, t_vals *vals)
{
	pid_t	pid;
	

	if (pipe(vals->pipe_fd) < 0)
		print_error();
	pid = fork();
	if(pid < 0)
		print_error();
	if (pid == 0)
		child_cmd(infile, vals);
	vals->num += 1;
	close(vals->pipe_fd[1]);
	dup2(vals->pipe_fd[0], STDIN_FILENO);
	close(vals->pipe_fd[0]);
	parent_cmd(outfile, vals);

	//comprobar si todos los procesos están terminados???



}



