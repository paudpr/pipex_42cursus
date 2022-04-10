#include <pipex.h>

void print_error(void)
{
	write(1, "ERROR\n", 6);
	exit(0);
}

void ft_free_double(char **array)
{
	int i;

	i = 0;
	while(array[i])
		i++;
	if (array[i - 1])
	{
		while(i >= 0)
			free(array[i--]);
		free(array);
	}
}

void	init_vals(t_vals *vals, char **environ, int argc, char **argv)
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
	vals->cmds_path = get_path(vals, argc, argv);
	vals->cmds_argv = get_argv(argv, argc);
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