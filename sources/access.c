#include <pipex.h>

//checks accesibility of the file named by the path argument
//for the access  permission indicated by the mode argument
int check_access(char **environ, char **argv, char **command)
{
	int fd;
	int pipe_fd[2];
	int i;
	pid_t pid;

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
		printf("%d\n", fd);
		if(fd < 0)
			print_error();
	printf("aqui\n");
		dup2(fd, STDIN_FILENO);
		close(fd);
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[1]);
		i = 0;
		if (execve(command[i], ft_split(argv[i], ' '), environ) < 0)
		{
			print_error();
			i++;
		}
	}
	// else
	// {

	// }
	// //ejecuta segundo comando
	// dup2(pipe_fd[0], STDIN_FILENO);
	// close(pipe_fd[0]);
	
	return(0);

}