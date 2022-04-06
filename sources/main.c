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


	pipex(argv[1], argv[argc - 1], cmd_path, environ)


	// pipe(pipe_fd);
	// printf("%d\n", pipe_fd[0]);
	// printf("%d\n", pipe_fd[1]);
	// if (pipe(pipe_fd) < 0)
	// 	print_error();
	// printf("PID PADRE = %d\n", getpid());
	// pid = fork();
	// printf("PID = %d\n %d\n", getpid(), pid);

	//con esto ejecuto 1 comando ->

	// cmd_split = ft_split(argv[2], ' ');
	// fd = open(argv[1], O_RDONLY);
	// if(fd < 0)
	// 	print_error();
	// dup2(fd, STDIN_FILENO);
	// close(fd);
	// printf("antes del execve\n");
	// printf("%s\n%s\n%s\n", ft_strjoin(cmd_path[0], cmd_split[0]), cmd_split[0], environ[0]);
	// fd = open(argv[3], O_RDWR | O_CREAT | O_TRUNC, 0644);
	// dup2(fd, STDOUT_FILENO);
	// close(fd);
	// if (execve(ft_strjoin(cmd_path[0], cmd_split[0]), cmd_split, environ) == -1)
	// 	print_error();
	// printf("despues del execve\n");

	// else
	// 	printf("paso a proceso padre\n");


	ft_free_double(cmd_split);
	ft_free_double(cmd_path);
	system("leaks -q pipex");

	return(0);
}
