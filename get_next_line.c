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
	int check;
	int reader;

	reader = 1;
	ind = 0;
	temp = "1";

	while(reader != 0)
	{
		if(!res[fd])
		{
			res[fd] = malloc(sizeof(char) * (BUFFER_SIZE + 1));
			if(res[fd] == NULL)
				return (-1);
			reader = read(fd, res[fd], BUFFER_SIZE);
			if(reader == -1)
				return(-1);
			res[fd][BUFFER_SIZE] = '\0';
		}
		null = ft_strchr(res[fd]);
		if(null == NULL && reader != 0)
		{
			line[0] + ind = ft_strdup(res[fd]);
			ind += ft_strlen(temp);
		}
		else if(*null == '\0' && reader != 0)
		{
			line[0][ind] = ft_strdup(res[fd]);
			// free(temp);
			return(0);
		}
		else if(reader != 0)
		{
			res[fd] = ft_strdup(null + 1);
			ft_strcpy(line[0] + ind, res[fd], null - res[fd]);
			ind += null - temp;
			line[0][ind] = '\0';
			// free(temp);
			return(1);
		}
	}
	// free(temp);
	return(0);
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
	printf("%s\n", test[0]);
	return 0;
}
