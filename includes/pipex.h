#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <libft.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>



/* Utils */
void print_error(void);

/* Path */
char *find_path(char **env);
void get_path (char **env);

#endif