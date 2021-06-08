#include "get_next_line_bonus.h"

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

char	*ft_strjoin(char *s1, char *s2, int dlina)
{
	int		count_s1;
	int		count_s2;
	char	*dest;

	if (s1 == NULL)
		return (s2);
	count_s1 = ft_strlen(s1);
	if (count_s1 == 0)
	{
		free(s1);
		return (s2);
	}
	count_s2 = dlina;
	dest = malloc((count_s1 + count_s2 + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	ft_strcpy(dest, s1, count_s1 + 1);
	dest += count_s1;
	*dest = '\0';
	ft_strcpy(dest, s2, count_s2 + 1);
	dest -= count_s1;
	if (s1 != NULL)
		free(s1);
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

char	*ft_calloc(size_t count, size_t size)
{
	char			*dst;
	unsigned int	total;
	unsigned int	i;

	total = count * size;
	dst = malloc(total);
	if (!dst)
		return (NULL);
	i = 0;
	while (total--)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}
