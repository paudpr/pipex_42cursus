#include <pipex.h>


//this is only until I actually use them
void print_argv(char **argv)
{
	int i;

	i = 0;
	while(argv[i])
	{
		printf("%s\n", argv[i]);
		i++;
	}
}

int main(int argc, char **argv)
{
	extern char	**environ;
	char		**cmd_path;
	int			pipe_fd[2];
	pid_t		pid;
	char		**cmd_split;
	int			fd;

	if(!environ)
		print_error();
	if (argc != 5)
		print_error();
	// print_argv(argv);


	cmd_path = get_path(environ, argc, argv);
	int i;
	i = -1;
	while(cmd_path[++i])
		printf("%s\n", cmd_path[i]);


	// int lalala;
	// lalala = check_access(environ, argv, cmd_path);
	// printf("lala -> %d\n", lalala);


	pipe(pipe_fd);
	printf("%d\n", pipe_fd[0]);
	printf("%d\n", pipe_fd[1]);
	if (pipe(pipe_fd) < 0)
		print_error();
	printf("PID PADRE = %d\n", getpid());
	pid = fork();
	printf("PID = %d\n", getpid());
	cmd_split = ft_split(argv[2], ' ');
	fd = open(argv[1], O_RDONLY);
	if(fd < 0)
		print_error();
	dup2(fd, STDIN_FILENO);
	printf("jhgfdsfghjhgfdsfghjgfdsghjkhgfdsfghjkjhgfdsfghjkljhgfdsdfghjkjhgfdsfghjkhgfdsfghjkhgfdsfghjgfd\n");
	close(fd);
	if(pid == 0)
	{
		printf("this is child process\n");
		execve(cmd_path[i], cmd_split, environ);
	}
	else
		printf("paso a proceso padre\n");



	ft_free_double(cmd_path);
	// system("leaks -q pipex");

	return(0);
}
