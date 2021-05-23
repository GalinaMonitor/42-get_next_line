#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	count;

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

	str = (char *)malloc(sizeof(char) * (BUFF + 1));
	if(str == NULL)
		return (NULL);
	if(read(fd, str, BUFF) == -1)
		return(NULL);
	return (str);
}


char	*ft_strchr(char *str)
{
	int count;

	count = BUFF;
	while (count-- > 0)
	{
		if (*str == '\n')
			return (str);
		str++;
	}
	return (NULL);
}

int	ft_strcpy(char *dest, char *src, size_t size)
{
	if (src == NULL)
		return (0);
	if (size == 0)
		return (0);
	while (*src && size > 0)
	{
		*dest = *src;
		dest++;
		src++;
		size--;
	}
	return (0);
}

// char	*ft_eof()

int	get_next_line(int fd, char **line)
{
	char *temp;
	char *null;
	static char	*res;
	int ind;

	ind = 0;
	temp = "1";
	while(*line != NULL)
	{
		temp = ft_read_line(fd);
		null = ft_strchr(temp);
		if(null == NULL)
		{
			ft_strcpy(line[0] + ind, temp, BUFF);
			ind += BUFF;
		}
		else
		{
			ft_strcpy(line[0] + ind, temp, null - temp);
			ind += null - temp;
			line[0][ind] = '\0';
			return(1);
		}
	}
	line[0][ind] = '\0';
	return(0);
}



int main(int argc, char **argv)
{
	int fd;
	char **test;
	test = malloc(sizeof(char *) * 2);
	test[0] = (char *)malloc(sizeof(char) * 100);
	fd = open(argv[1], O_RDONLY);
	get_next_line(fd, test);
	return 0;
}
