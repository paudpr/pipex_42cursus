#include <pipex.h>

char	*find_path(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strnstr(env[i], "PATH=", 5))
			return (env[i]);
		i++;
	}
	return (NULL);
}

char	*check_valid(char *path, char *argv)
{
	int		i;
	char	**path_div;
	char	*aux;
	char	*str_cmd;
	char	*cmd_path;

	path_div = ft_split(path, ':');
	cmd_path = NULL;
	i = 0;
	while (path_div[i])
	{
		aux = ft_strjoin(path_div[i], "/");
		str_cmd = ft_strjoin(aux, argv);
		if (access(str_cmd, F_OK) == 0)
			cmd_path = ft_strdup(aux);
		free(aux);
		free(str_cmd);
		i++;
	}
	ft_free_double(path_div);
	if(cmd_path == NULL)
		print_error();
	return (cmd_path);
}

char	**get_path(t_vals *vals, int argc, char **argv)
{
	int		i;
	int		j;
	char	*path;
	char	**cmd_path;
	char	**argv_split;

	path = find_path(vals->env);
	cmd_path = malloc(sizeof(char *) * (argc - 3 + 1));
	if (cmd_path == NULL)
		print_error();
	i = 2;
	j = 0;
	//acordarme de poner el -1 despues de argc en la condición cuando deje de hacer pruebas de un solo comando
	while (argv[i] && i > 1 && i < argc - 1)
	{
		argv_split = ft_split(argv[i], ' ');
		cmd_path[j] = check_valid(path, argv_split[0]);
		j++;
		i++;
		ft_free_double(argv_split);
	}
	cmd_path[j] = NULL;
	//asegurar aqui que ninguno sea null excepto el ultimo para que no me cuelen que faltan comandos
	return (cmd_path);
}
