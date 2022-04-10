#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define BLUE "\033[1;34m"
# define CYAN "\033[1;36m"
# define GREY "\033[1;90m"
# define YELLOW "\033[1;33m"
# define MAGENTA "\033[1;35m"
# define RESET "\033[0m"

#include <libft.h>
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
}	t_vals;

/* Utils */
void print_error(void);
void ft_free_double(char **array);

char **get_argv(char **argv, int argc);

/* Path */
char *find_path(char **env);
char **get_path(t_vals *vals, int argc, char **argv);

/* Access */
int check_access(char **environ, char **argv, char **command);

/* Pipex */
void pipex(char *infile, char *outfile, t_vals *vals, char **argv);

#endif