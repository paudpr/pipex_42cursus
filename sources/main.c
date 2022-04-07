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
	// char		**cmd_path;
	// pid_t		pid;
	// char		**cmd_split;
	// int			fd;
	t_vals		vals;


	if(!environ)
		print_error();
	// if (argc != 5)
	// 	print_error();
	// print_argv(argv);

	init_vals(&vals, environ);
	vals.cmds_path = get_path(&vals, argc, argv);
	// vals.cmds_opts = get_opts(&vals, argv, argv);
	int i;
	i = -1;
	while(vals.cmds_path[++i])
		printf("%s\n", vals.cmds_path[i]);
	printf("\n");
	// i = 2;
	// int j;
	// j = 0;
	// while(argv[i] && i > 1 && i < argc - 1)
	// {
	// 	printf("argv[i] -> %s\n", argv[i]);
	// 	printf("i -> %d\n", i);
	// 	// vals.cmds_opts[j] = argv[i];
	// 	printf("jkhggfdsghjhgfd\n");
	// 	i++;
	// }
	// printf("%s\n", vals.cmds_opts[0]);



	pipex(argv[1], argv[argc - 1], &vals, argv);

	printf("Aqui\n");



	// ft_free_double(vals.cmds_path);
	// ft_free_double(vals.cmds_opts);
	system("leaks -q pipex");

	return(0);
}
