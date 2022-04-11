#include <pipex.h>

int	main(int argc, char **argv)
{
	extern char	**environ;
	t_vals		vals;

	if (!environ)
		print_error();
	init_vals(&vals, environ, argc, argv);
	// if(ft_strncmp(vals.cmds_argv[0], "here_doc", 8) == 0)
	// 	heredoc();
	pipex(argv[1], argv[argc - 1], &vals);
	return (0);
}
