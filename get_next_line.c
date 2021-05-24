#include "get_next_line.h"

int	ft_strcpy(char *dest, char *src, int size)
{
	if (src == NULL)
		return (0);
	if (size == 0)
		return (0);
	while (size > 0)
	{
		*dest = *src;
		dest++;
		src++;
		size--;
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char *temp;
	char *null;
	static char	*res[1024]; ///CHECK
	int ind;

	ind = 0;
	temp = "1";
	while(temp != NULL)
	{
		if(res[fd])
		{
			temp = ft_strjoin(res[fd], ft_read_line(fd));
			free(res[fd]);
			res[fd] = NULL;
			null = ft_strchr(temp, ft_strlen(temp));
		}
		else
		{
			temp = ft_read_line(fd);
			null = ft_strchr(temp, BUFFER_SIZE);
		}
		if(null == NULL)
		{
			ft_strcpy(line[0] + ind, temp, ft_strlen(temp));
			ind += ft_strlen(temp);
		}
		else if(*null == '\0')
		{
			ft_strcpy(line[0] + ind, temp, null - temp);
			return(0);
		}
		else
		{
			*null = '\0';
			res[fd] = ft_strdup(null + 1);
			ft_strcpy(line[0] + ind, temp, null - temp);
			ind += null - temp;
			line[0][ind] = '\0';
			return(1);
		}
	}
	return(-1);
}
int main(int argc, char **argv)
{
	(void)argc;
	int fd;
	char **test;
	test = malloc(sizeof(char *) * 2);
	test[0] = (char *)malloc(sizeof(char) * 100);
	fd = open(argv[1], O_RDONLY);
	while(get_next_line(fd, test) != 0)
	{
		printf("%s\n", test[0]);
	}
	return 0;
}
