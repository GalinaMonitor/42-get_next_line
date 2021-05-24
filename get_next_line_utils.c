#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		count++;
		str++;
	}
	return (count);
}

char	*ft_read_line(int fd)
{
	char *str;

	str = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if(str == NULL)
		return (NULL);
	if(read(fd, str, BUFFER_SIZE) == -1)
		return(NULL);
	return (str);
}


char	*ft_strchr(char *str, int count)
{
	while (count-- > 0)
	{
		if (*str == '\n')
			return (str);
		else if (*str == '\0')
		{
			return (str);
		}
		str++;
	}
	return (NULL);
}

char	*ft_strdup(char *s)
{
	int	size;
	char	*str;

	size = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	ft_strcpy(str, s, size + 1);
	// str[size] = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		count_s1;
	int		count_s2;
	char	*dest;

	if (s1 == NULL || s2 == NULL)  /////*&YYGUVLUVGB
		return (NULL);
	count_s1 = ft_strlen(s1);
	count_s2 = BUFFER_SIZE;
	dest = (char *)malloc((count_s1 + count_s2 + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	ft_strcpy(dest, s1, count_s1 + 1);
	dest += count_s1;
	*dest = '1';
	ft_strcpy(dest, s2, count_s2 + 1);
	dest -= count_s1;
	return (dest);
}
