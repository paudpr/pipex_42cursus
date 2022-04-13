#include <pipex.h>

int	main(int argc, char **argv, char **environ)
{
	// extern char	**environ;
	t_vals		vals;
	char *infile;

	if (!environ)
		print_error();
	if (argc < 5)
		print_error();
	infile = NULL;
	if(ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		infile = heredoc(argv);
		vals.num = 1;
	}	
	init_vals(&vals, environ, argc, argv);
	if (infile == NULL)
		infile = argv[1];
	pipex(infile, argv[argc - 1], &vals);
	return(0);
}
