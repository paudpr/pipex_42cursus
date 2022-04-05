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
