#include "get_next_line_bonus.h"

char	*ft_strcut(char *buff)
{
	int		ind;
	char	*res;

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
	int		ind;
	int		ind2;
	char	*res;

	if (buff == NULL)
		return (NULL);
	ind = 0;
	ind2 = 0;
	while (buff[ind] != '\n' && buff[ind] != '\0')
		ind++;
	if (buff[ind] == '\0')
	{
		free(buff);
		return (NULL);
	}
	ind++;
	res = malloc(sizeof(char) * (ft_strlen(buff + ind) + 1));
	while (buff[ind])
		res[ind2++] = buff[ind++];
	free(buff);
	res[ind2] = '\0';
	return (res);
}

int	ft_read_and_join(char **line, char **buff, int fd)
{
	char	*temp;
	int		text;

	temp = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (temp == NULL)
		return (-1);
	text = read(fd, temp, BUFFER_SIZE);
	if (text <= 0 && buff[fd] == NULL)
	{
		*line = malloc(1);
		**line = '\0';
		free(temp);
		return (-2);
	}
	temp[text] = '\0';
	buff[fd] = ft_strjoin(buff[fd], temp, text);
	return (text);
}

int	get_next_line(int fd, char **line)
{
	static char	*buff[256];
	int			text;

	if ((!line) || (BUFFER_SIZE <= 0) || (read(fd, buff, 0) < 0))
		return (-1);
	text = 1;
	while (ft_check_buff(buff[fd]) != 1 && text >= 1)
	{
		text = ft_read_and_join(line, buff, fd);
		if (text == -1)
			return (-1);
		if (text == -2)
			return (0);
	}
	line[0] = ft_strcut(buff[fd]);
	buff[fd] = ft_save(buff[fd]);
	if (text == 0)
	{
		free(buff[fd]);
		return (0);
	}
	return (1);
}
