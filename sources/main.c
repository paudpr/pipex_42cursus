#include <pipex.h>

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
	ft_bzero(vals->pipe_fd, 2);
}

char **get_argv(char **argv, int argc)
{
	char **cmd_argv;
	int i;
	int j;

	cmd_argv = malloc(sizeof(char *) * argc - 3);
	if (cmd_argv == NULL)
		print_error();
	i = 2;
	j = 0;
	while (argv[i] && i > 1 && i < argc - 1)
	{
		cmd_argv[j] = argv[i];
		i++;
		j++;
	}
	cmd_argv[j] = NULL;
	return(cmd_argv);
}

int main(int argc, char **argv)
{
	extern char	**environ;
	t_vals		vals;


	if(!environ)
		print_error();
	// if (argc != 5)
	// 	print_error();

	init_vals(&vals, environ);
	vals.cmds_path = get_path(&vals, argc, argv);
	vals.cmds_argv = get_argv(argv, argc);
	

	int i;
	i = 0;
	while(vals.cmds_path[i])
	{
	printf("estoy aqui \n");
		printf("%s\n", vals.cmds_path[i]);
		i++;
	}




	// pipex(argv[1], argv[argc - 1], &vals, argv);




	// ft_free_double(vals.cmds_path);
	// ft_free_double(vals.cmds_opts);
	system("leaks -q pipex");

	return(0);
}
