#include <pipex.h>

void files(char **argv)
{
	int fd;
	int i;

	i = 0;
	while(argv[i])
	{
		fd = open(argv[i], O_RDONLY);

	}
}