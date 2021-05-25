#include "get_next_line.h"


#include <string.h>

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
	if(fd >= 1024 || fd < 0 || line == NULL)
		return(-1);
	char *temp;
	char *null;
	static char	*res[1024]; ///CHECK
	int ind;

	ind = 0;
	temp = "1";
	while(temp != NULL && line != NULL)
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
			line[0][ind] = '\0';
			// free(temp);
			return(0);
		}
		else
		{
			res[fd] = ft_strdup(null + 1);
			ft_strcpy(line[0] + ind, temp, null - temp);
			ind += null - temp;
			line[0][ind] = '\0';
			// free(temp);
			return(1);
		}
	}
	// free(temp);
	return(-1);
}
int main(int argc, char **argv)
{
	(void)argc;
	int fd;
	char **test;
	test = malloc(sizeof(char *) * 2);
	test[0] = malloc(sizeof(char) * 1000000000000);
	fd = open(argv[1], O_RDWR);
	while(get_next_line(fd, test) != 0)
	{
		printf("%s\n", test[0]);
	}
	return 0;
}
