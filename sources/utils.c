#include <pipex.h>

void print_error(void)
{
	write(1, "ERROR\n", 6);
	exit(0);
}