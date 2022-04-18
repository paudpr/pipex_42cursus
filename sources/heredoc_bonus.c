/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-pin <pdel-pin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:10:10 by pdel-pin          #+#    #+#             */
/*   Updated: 2022/04/18 13:10:12 by pdel-pin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	check_herefile(char *infile)
{
	if (ft_strncmp(infile, "/tmp/file", 9) == 0)
	{
		unlink("/tmp/file");
		if (access("/tmp/file", F_OK) == 0)
			print_error(0);
	}
}

void	create_file(char *infile)
{
	int	fd;
	int	i;

	fd = open("/tmp/file", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		print_error(0);
	if (infile != NULL)
	{
		i = -1;
		while (infile[++i])
			write(fd, &infile[i], 1);
	}
}

static void	heredoc_loop(t_heredoc *vars)
{
	char	*aux;

	aux = ft_strdup(vars->infile);
	free(vars->infile);
	vars->infile = ft_strjoin(aux, vars->line);
	free(vars->line);
	free(aux);
	vars->line = get_next_line(0);
}

void	heredoc(char **argv)
{
	t_heredoc	vars;

	vars.len = ft_strlen(argv[2]);
	vars.infile = get_next_line(0);
	if (ft_strncmp(argv[2], vars.infile, vars.len) != 0
		|| vars.infile[vars.len] != '\n')
	{
		vars.line = get_next_line(0);
		while (ft_strncmp(argv[2], vars.line, vars.len) != 0
			|| vars.line[vars.len] != '\n')
		{
			heredoc_loop(&vars);
		}
		free(vars.line);
		free(vars.infile);
	}
	else
	{
		free(vars.infile);
		vars.infile = 0;
	}
	create_file(vars.infile);
}
