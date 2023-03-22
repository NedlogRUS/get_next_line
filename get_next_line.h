
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char	*ft_strchr(const char *s, int c);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strclr(char *str);
char	*ft_strnew(char *str);
int     ft_strlen(const char *s);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char    *checkmem(char *mem, char **out);
char    *get_next_line(int fd);

#endif
