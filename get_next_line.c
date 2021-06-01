#include "get_next_line.h"


#include <string.h>

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

	str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if(str == NULL)
		return (NULL);
	if(read(fd, str, BUFFER_SIZE) == -1)
		return(NULL);
	str[BUFFER_SIZE] = '\0';
	return (str);
}


char	*ft_strchr(char *str)
{
	while (*str)
	{
		if (*str == '\n' || *str == '\0')
			return (str);
		str++;
	}
	return (NULL);
}


char	*ft_strjoin(char *s1, char *s2)
{
	int		count_s1;
	int		count_s2;
	char	*dest;

	if (s1 == NULL)
		return (s2);
	count_s1 = ft_strlen(s1);
	if (count_s1 == 0)
		return (s2);
	count_s2 = BUFFER_SIZE;
	dest = malloc((count_s1 + count_s2 + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	ft_strcpy(dest, s1, count_s1 + 1);
	dest += count_s1;
	*dest = '1';
	ft_strcpy(dest, s2, count_s2 + 1);
	dest -= count_s1;
	free(s2);
	return (dest);
}


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


int	ft_check_buff(char *buff)
{
	while (buff && *buff)
	{
		if (*buff == '\n')
			return (1);
		buff++;
	}
	return (0);
}



char	*ft_strcut(char *buff)
{
	int ind;
	char *res;

	ind = 0;
	if (buff == NULL)
		return (NULL);
	while (buff[ind] != '\n' && buff[ind] != '\0')
	{
		ind++;
	}
	res = malloc(sizeof(char) * (ind + 1));
	if (res == NULL)
		return (NULL);
	ind = 0;
	while (buff[ind] != '\n' && buff[ind] != '\0')
	{
		res[ind] = buff[ind];
		ind++;
	}
	res[ind] = '\0';
	return (res);
}

char	*ft_save(char *buff)
{
	int ind;
	int ind2;
	char *res;

	if(buff == NULL)
		return (NULL);
	ind = 0;
	ind2 = 0;
	while (buff[ind] != '\n' && buff[ind] != '\0')
		ind++;
	ind++;
	res = malloc(sizeof(char) * (ft_strlen(buff + ind) + 2));
	while (buff[ind])
	{
		res[ind2] = buff[ind];
		ind++;
		ind2++;
	}
	free(buff);
	res[ind2] = '\0';
	return (res);
}




int	get_next_line(int fd, char **line)
{
	char *temp;
	static char	*buff[OPEN_MAX]; //check
	// int ind;
	int text;

	if (fd > OPEN_MAX || fd < 0 || line == NULL)
		return (-1);
	text = 1;
	while (ft_check_buff(buff[fd]) != 1 && text >= 1)
	{
		temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (temp == NULL)
			return (-1);
		text = read(fd, temp, BUFFER_SIZE);
		temp[text] = '\0';
		buff[fd] = ft_strjoin(buff[fd], temp);

	}
	line[0] = ft_strcut(buff[fd]);
	buff[fd] = ft_save(buff[fd]);
	if (text == 0)
		return 0;
	return (1);
}



// int main(int argc, char **argv)
// {
// 	(void)argc;
// 	int fd;
// 	char *test;
// 	fd = open(argv[1], O_RDWR);
// 	while(get_next_line(fd, &test) != 0)
// 		printf("%s\n", test);
// 	printf("%s\n", test);
// 	return 0;
// }
