#include <pipex.h>

//checks accesibility of the file named by the path argument
//for the access  permission indicated by the mode argument
int check_access(char **environ, char **argv, char **cmd_path)
{
	int fd;
	int pipe_fd[2];
	int i;
	pid_t pid;
	char **cmd_split;

	//ejecta primer comando
	if(pipe(pipe_fd) < 0)
		print_error();
	pid = fork();
	printf("PID PADRE = %d\n", getpid());
	if(pid < 0)
		print_error();
	if(pid == 0)
	{
		close(pipe_fd[0]);
		fd = open(argv[1], O_RDONLY);
		if(fd < 0)
			print_error();
	printf("aqui\n");
		i = 0;
		cmd_split = ft_split(argv[2], ' ');
		printf("\n\n");
		printf("%s\n", cmd_split[0]);
		printf("%s\n", cmd_split[1]);
		printf("%s\n", cmd_path[0]);
		printf("execve -> %d\n", execve(cmd_path[i], cmd_split, environ));
		printf("hgfdsfdgffhggff\n");
		dup2(fd, STDIN_FILENO);
		close(fd);
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[1]);
		if (execve(cmd_path[i], cmd_split, environ) < 0)
		{
			printf("execve -> %d\n", execve(cmd_path[i], cmd_split, environ));
			print_error();
			i++;
		}
		ft_free_double(cmd_split);
		exit(0);
	}
	// else
	// {

	// }
	// //ejecuta segundo comando
	// dup2(pipe_fd[0], STDIN_FILENO);
	// close(pipe_fd[0]);
	
	return(0);

}