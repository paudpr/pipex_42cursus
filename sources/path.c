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

void check_valid(char **path_div, int argc, char **argv)
{
	int i;
	int mark;
	char *aux;
	char *path;

	i = 2;
	mark = -1;
	while(i > 1 && i < argc - 1)
	{
		aux = ft_strjoin(*path_div, "/");
		path = ft_strjoin(aux, argv[i]);
		free(aux);
		//todos tienen que ser comandos o no cumple
		//algo pasa aqui que no funciona bien
		printf("valor access -> %d\n", access(path, F_OK));
		printf("pathh -> %s\n", path);

		//meh, el error es que no puede ser que sea error, tiene que ser otra cosa
		if (access(path, F_OK) > mark)
			mark = 0;
		printf("hgfds\n");
		free(path);
		i++;
	}
	if (mark == 0)
		printf("it is command\n");

		//ahcer que devuelva mark y con eso ahcer el array de paths
	return ;
}

void get_path(char **env, int argc, char **argv)
{
	char *path;
	char **path_div;
	int i;

	path = find_path(env);
	path_div = ft_split(path, ':');
	i = 0;
	while(path_div[i])
	{
		check_valid(&path_div[i], argc, argv);
		printf("despues de \n\n");
		i++;
	}
	ft_free_double(path_div);
}