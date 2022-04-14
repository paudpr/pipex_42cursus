#include <pipex.h>

int	main(int argc, char **argv, char **environ)
{
	t_vals		vals;

	if (!environ)
		print_error(0);
	if (argc != 5)
		print_error(0);
	init_vals(&vals, environ, argc, argv);
	pipex(argv[1], argv[argc - 1], &vals);
	return (0);
}
