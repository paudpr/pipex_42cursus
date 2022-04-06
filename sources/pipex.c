#include <pipex.h>


// 	int		fd;
// 	pid_t	pid;

// 	pid = fork();
// 	if (pid == -1)
// 		ft_free_error(cmds);
// 	if (pid == 0)
// 	{
// 		fd = open(file, O_CREAT | O_RDWR | O_TRUNC, 0644);
// 		if (fd < 0)
// 			exit(1);
// 		dup2(fd, STDOUT_FILENO);
// 		close(fd);
// 		if (execve(get_path(envp, cmds[cmd_nbr][0]), cmds[cmd_nbr], envp) == -1)
// 		{
// 			write(2, "command not found\n", 18);
// 			free_machine(cmds);
// 			exit(127);
// 		}
// 	}
// }


void child_cmd(char *infile, t_vals *vals, char **argv)
{
	int		i;
	int		fd;
	char	*cmd;

	close(vals->pipe_fd[0]);
	fd = open(infile, O_RDONLY);
	if(fd < 0)
		print_error();
	i = 0;
	vals->cmds_opts = ft_split(argv[2], ' ');
	dup2(fd, STDIN_FILENO);
	close(fd);
	dup2(vals->pipe_fd[1], STDOUT_FILENO);
	close(vals->pipe_fd[1]);
	cmd = ft_strjoin(vals->cmds_path[0], argv[2]);
	if (execve(cmd, ft_split(vals->cmds_opts, ' '), vals->env) < 0)
			print_error();
	ft_free_double(vals->cmds_opts);
}

void parent_cmd(char *outfile, t_vals *vals)
{
	int fd;
	int i;
	
	fd = open(outfile, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		print_error();
	dup2(fd, STDOUT_FILENO);
	close(fd);
	i = 0;
	if(execve(cmds[i], cmd_split, vals->env))
		print_error();
}

void pipex(char *infile, char *outfile, t_vals *vals, char **argv)
{
	int		i;
	int		fd;
	pid_t	pid;
	

	if (pipe(vals->pipe_fd) < 0)
		print_error();
	pid = fork();
	if(pid < 0)
		print_error();
	if (pid == 0)
		child_cmd(infile, vals, argv);
	else
	{
		close(vals->pipe_fd[0]);
		dup2(vals->pipe_fd[1], STDIN_FILENO);
		close(vals->pipe_fd[1]);
		parent_cmd(outfile, cmds, env);

	}
	
	//comprobar si todos los procesos están terminados???



}



