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

/* Libft */
void	ft_bzero(void *s, size_t n);
char	**ft_split(const char *s, char c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *b, int c, size_t len);

/* Utils */
void	print_error(void);
void	ft_free_double(char **array);
char	**get_argv(char **argv, int argc);
void	init_vals(t_vals *vals, char **environ, int argc, char **argv);

/* Path */
char	*find_path(char **env);
char	**get_path(t_vals *vals, int argc, char **argv);

/* Pipex */
void	pipex(char *infile, char *outfile, t_vals *vals);

/* Bonus */

#endif