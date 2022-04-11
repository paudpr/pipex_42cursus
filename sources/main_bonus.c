#include <pipex.h>

int	main(int argc, char **argv)
{
	extern char	**environ;
	t_vals		vals;

	if (!environ)
		print_error();
	if (argc < 5)
		print_error();
	init_vals(&vals, environ, argc, argv);
	// if(ft_strncmp(vals.cmds_argv[0], "here_doc", 8) == 0)
	// 	heredoc();
	pipex(argv[1], argv[argc - 1], &vals);
	
	
	
	
	
	
	// while(1)
	// {
	// 	execve("/bin/ls", ft_split("ls -l -a", ' '), environ);	
	// }
	// printf("54653435\n");
	// execve("/bin/ls", ft_split("ls", ' '), environ);
	// printf("lslslsls\n");
	// 	execve("/usr/bin/wc", ft_split("wc", ' '), environ);
	return (0);
}
