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

void	init_vals(t_vals *vals, char **environ)
{
	int i;

	i = 0;
	while(environ[i])
		i++;
	vals->env = malloc(sizeof(char *) * i);
	if(vals->env == NULL)
		return ;
	i = 0;
	while(environ[i])
	{
		vals->env[i] = ft_strdup(environ[i]);
		i++;
	}
	vals->env[i] = NULL;
	// vals->cmds_path = NULL;
	// vals->cmds_opts = NULL;
	ft_bzero(vals->pipe_fd, 2);
}


int main(int argc, char **argv)
{
	extern char	**environ;
	char		**cmd_path;
	pid_t		pid;
	char		**cmd_split;
	int			fd;
	t_vals		vals;


	if(!environ)
		print_error();
	if (argc != 5)
		print_error();
	// print_argv(argv);

	init_vals(&vals, environ);
	printf("%s\n", vals.env[0]);
	printf("%d, %d\n", vals.pipe_fd[0], vals.pipe_fd[1]);

	vals.cmds_path = get_path(&vals, argc, argv);
	int i;
	i = -1;
	while(vals.cmds_path[++i])
		printf("%s\n", vals.cmds_path[i]);
	i = 2;
	int j;
	j = 0;
	while(argv[i] && i > 1 && i < argc - 1)
	{
		printf("argv[i] -> %s\n", argv[i]);
		printf("i -> %d\n", i);
		vals.cmds_opts[j] = argv[i];
		printf("jkhggfdsghjhgfd\n");
		i++;
	}
	printf("Aqui\n");
	printf("%s\n", vals.cmds_opts[0]);



	// pipex(argv[1], argv[argc - 1], &vals);


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


	// ft_free_double(vals.cmds_path);
	// ft_free_double(vals.cmds_opts);
	system("leaks -q pipex");

	return(0);
}
