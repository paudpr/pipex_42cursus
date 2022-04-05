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
	// int			fd[2];
	// pid_t		pid;

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

	int lalalalalla;
	lalalalalla = check_access(environ, argv, cmd_path);



	// pipe(fd);
	// printf("%d\n", fd[0]);
	// printf("%d\n", fd[1]);
	// if (pipe(fd) < 0)
	// 	print_error();
	// pid = fork();
	// if(pid == 0)
	// 	printf("this is child process\n");


	ft_free_double(cmd_path);
	system("leaks -q pipex");

	return(0);
}
