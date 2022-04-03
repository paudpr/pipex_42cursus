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
	{
		free(array[i]);
		i++;
	}
	free(array);
}