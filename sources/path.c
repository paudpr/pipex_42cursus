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

void get_path (char **env)
{
	char *path;

	path = find_path(env);
	printf("%s\n", path);
}