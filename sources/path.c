#include <pipex.h>

char *find_path(char **env)
{
	int i;

	i = 0;
	while(env[i])
	{
		if (ft_strnstr(env[i], "PATH=", 5))
			return (env[i]);
		i++;
	}

	return (NULL);
}

void ft_free_double(char **array)
{
	int i;

	i = 0;
	while(array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

char **check_valid(char **path_div, int argc, char **argv)
{
	int i;
	int j;
	char *aux;
	char *path;
	char **commands;

	i = 2;
	commands = malloc(sizeof(char *) * (argc - 3));
	if (commands == NULL)
		print_error();
	j = 0;
	while(i > 1 && i < argc - 1)
	{
		aux = ft_strjoin(*path_div, "/");
		path = ft_strjoin(aux, argv[i]);
		free(aux);
		if (access(path, F_OK) == 0)
		{
			commands[j] = ft_strdup(argv[i]);
			// ft_memcpy(commands[j], argv[i], ft_strlen(argv[i]));
			// ft_strlcpy(commands[j], argv[i], ft_strlen(argv[i]));
			// ft_memmove(commands[j], argv[i], ft_strlen(argv[i]));
			j++;
		}
		// else
		// 	printf("argv[%d] NO es un comando\n\n", i);
		free(path);
		i++;
	}
	return(commands);
}

void get_path(char **env, int argc, char **argv)
{
	char *path;
	char **path_div;
	char **commands;
	int i;

	path = find_path(env);
	path_div = ft_split(path, ':');
	i = 0;
	while(path_div[i])
	{
		commands = check_valid(&path_div[i], argc, argv);
		i++;
	}
	ft_free_double(path_div);
}