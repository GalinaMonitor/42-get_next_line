#ifndef GET_NEXT_LINE_H

#define GET_NEXT_LINE_H

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <limits.h>

// #define OPEN_MAX 1024
// #define BUFFER_SIZE 10
int	ft_strlen(char *str);
char	*ft_read_line(int fd);
char	*ft_strchr(char *str);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2, int dlina);
int	get_next_line(int fd, char **line);
int	ft_strcpy(char *dest, char *src, int size);

#endif
