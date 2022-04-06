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


void child_cmd(char *infile, t_vals *vals)
{
	int		fd;
	char	**cmd_split;

	close(pipe_fd[0]);
	fd = open(infile, O_RDONLY);
	if(fd < 0)
		print_error();
	i = 0;
	cmd_split = ft_split(argv[i])
	dup2(fd, STDIN_FILENO);
	close(fd);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[1]);
	if (execve(cmds[i], cmd_split, environ) < 0)
	{
		printf("execve -> %d\n", execve(cmds[i], cmd_split, environ));
		i++;
		print_error();
	}
	ft_free_double(cmd_split);
}

void parent_cmd(char *outfile, char **cmds, char **env)
{
	int fd;
	
	fd = open(outfile, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		print_error();
	dup2(fd, STDOUT_FILENO);
	close(fd);
	if(execve(cmds[i], cmd_split, environ))
		print_error();
}

void pipex(char *infile, char *outfile, t_vals *vals)
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
		child_cmd(infile, vals);
	else
	{
		dup2(vals->pipe_fd[1], STDIN_FILENO);
		close(vals->pipe_fd[0]);
		close(vals->pipe_fd[1]);
		parent_cmd(outfile, cmds, env);

	}
	
	//comprobar si todos los procesos están terminados???



}



