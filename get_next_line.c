#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int	get_next_line(int fd, char **line)
{
	int		check = 0;
	int		buff = 3;
	int		temp_buff;
	char	temp[buff];
	int		ind = 0;

	temp_buff = buff;
	while(check++ != 5)
	{
		read(fd, temp, buff);
		while(temp[ind] != '\n' && temp[ind] != '\0')
		{
			char ddd = temp[ind];
			temp_buff--;
			ind++;
		}
		ind = 0;
		temp_buff = buff;
		printf("%s ", temp);
	}


	return 0;
}

int main(int argc, char **argv)
{
	int fd;
	char **test;
	fd = open(argv[1], O_RDONLY);
	fd = get_next_line(fd, test);
	return 0;
}
