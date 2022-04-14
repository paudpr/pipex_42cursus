#ifndef PIPEX_H
# define  PIPEX_H

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define BLUE "\033[1;34m"
# define CYAN "\033[1;36m"
# define GREY "\033[1;90m"
# define YELLOW "\033[1;33m"
# define MAGENTA "\033[1;35m"
# define RESET "\033[0m"

#include "../functions/functions.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

// printf(BLUE"%s"RESET"\n", *path_div);

typedef struct s_vals
{
	char	**env;
	char	**cmds_path;
	char	**cmds_argv;
	int		pipe_fd[2];
	int		num;
}	t_vals;

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