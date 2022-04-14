#include <pipex.h>

void check_herefile(char *infile)
{
	if (ft_strncmp(infile, "/tmp/file", 9) == 0)
	{
		unlink("/tmp/file");
		if(access("/tmp/file", F_OK) == 0)
			print_error(0);
	}
}

void create_file(char *infile)
{
	int	fd;
	int	i;

	fd = open("/tmp/file", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		print_error(0);
	i = -1;
	while (infile[++i])
		write(fd, &infile[i], 1);
}

void	heredoc(char **argv)
{
	char	*line;
	char	*aux;
	char	*infile;

	line = get_next_line(0);
	aux = NULL;
	infile = NULL;
	while (ft_strncmp(argv[2], line, ft_strlen(argv[2])) != 0)
	{
		if (aux == NULL)
		{
			infile = ft_strdup(line);
			free(line);
			line = get_next_line(0);
		}
		aux = ft_strdup(infile);
		free(infile);
		infile = ft_strjoin(aux, line); 
		free(line);
		free(aux);
		line = get_next_line(0);
	}
	free(line);
	if (infile != NULL)
		create_file(infile);
}














// void	heredoc(char **argv)
// {
// 	int		i;
// 	char	*line;
// 	char	*aux;
// 	char	*infile;

// 	line = get_next_line(0);
// 	i = ft_strlen(argv[2]);
// 	aux = NULL;
// 	infile = NULL;
// 	while (ft_strncmp(argv[2], line, i) != 0)
// 	{
// 		if (aux == NULL)
// 		{
// 			infile = line;
// 			line = get_next_line(0);
// 		}
// 		if (infile != NULL)
// 		{
// 			aux = ft_strdup(infile);
// 			infile = ft_strjoin(aux, line); 
// 		}
// 		free(line);
// 		free(aux);
// 		line = get_next_line(0);
// 	}
// 	create_file(infile);
// }
