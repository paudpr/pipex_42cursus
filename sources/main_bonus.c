#include <pipex.h>

int	main(int argc, char **argv, char **environ)
{
	t_vals		vals;
	char		*infile;

	if (!environ)
		print_error(0);
	if (argc < 5)
		print_error(0);
	infile = NULL;
	vals.num = 0;
	if(ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		heredoc(argv);
		vals.num = 1;
		infile = "/tmp/file";
	}
	if (infile == NULL)
		infile = argv[1];
	init_vals(&vals, environ, argc, argv);
	// system("leaks -q pipex");
	// pipex(infile, argv[argc - 1], &vals);
	return(0);
}
