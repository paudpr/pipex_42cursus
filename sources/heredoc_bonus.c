#include <pipex.h>

char	*heredoc(char **argv)
{
	int		i;
	char	*line;
	char	*aux;
	char	*infile;

	line = get_next_line(0);
	i = ft_strlen(argv[2]);
	while (ft_strncmp(argv[2], line, i) != 0)
	{
		aux = ft_strjoin(line, "\n");
		free(line);
		infile = ft_strjoin(infile, aux);
		free(aux);
		line = get_next_line(0);
	}
	return(infile);
}