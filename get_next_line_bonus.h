#ifndef GET_NEXT_LINE_BONUS_H

# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 200
# endif

int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2, int dlina);
int		get_next_line(int fd, char **line);
int		ft_strcpy(char *dest, char *src, int size);
int		ft_read_and_join(char **line, char **buff, int fd);
char	*ft_calloc(size_t count, size_t size);
int		ft_check_buff(char *buff);

#endif
