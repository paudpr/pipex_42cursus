#include <pipex.h>

int main(int argc, char **argv)
{
	extern char	**environ;
	t_vals		vals;


	if(!environ)
		print_error();
	if (argc != 5)
		print_error();

	init_vals(&vals, environ, argc, argv);
	pipex(argv[1], argv[argc - 1], &vals);
	return(0);
}
