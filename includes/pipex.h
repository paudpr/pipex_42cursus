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

/* Utils */
void print_error(void);
void ft_free_double(char **array);

/* Path */
char *find_path(char **env);
void get_path(char **env, int argc, char **argv);

#endif