/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-pin <pdel-pin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:12:59 by pdel-pin          #+#    #+#             */
/*   Updated: 2022/04/18 13:13:22 by pdel-pin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define  PIPEX_H

# include "../functions/functions.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/wait.h>

typedef struct s_vals
{
	char	**env;
	char	**cmds_path;
	char	**cmds_argv;
	int		pipe_fd[2];
	int		num;
}	t_vals;

typedef struct s_heredoc
{
	char	*infile;
	char	*line;
	int		len;
}	t_heredoc;

/* Utils */
void	print_error(char *s);
void	ft_free_double(char **array);
char	**get_argv(t_vals *vals, char **argv, int argc);
void	init_vals(t_vals *vals, char **environ, int argc, char **argv);

/* Path */
char	*find_path(char **env);
char	**get_path(t_vals *vals, int argc, char **argv);

/* Pipex */
void	pipex(char *infile, char *outfile, t_vals *vals);
void	child_cmd(char *infile, t_vals *vals);
void	parent_cmd(char *outfile, t_vals *vals);

/* Bonus */
void	heredoc(char **argv);
void	exec(t_vals *vals);
pid_t	exec_child(t_vals *vals);
void	check_herefile(char *infile);

#endif