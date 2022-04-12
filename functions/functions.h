#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# define FILE_SIZE 4096

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include	<fcntl.h>
# include	<stdlib.h>
# include	<unistd.h>
# include	<stdio.h>

void	ft_bzero(void *s, size_t n);
char	**ft_split(const char *s, char c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *b, int c, size_t len);
char	*get_next_line(int fd);
void	*ft_calloc(size_t count, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);

#endif