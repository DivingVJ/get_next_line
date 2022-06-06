#include "get_next_line.h"

void	free_mem(char **str)
{
	free(*str);
	*str = NULL;
}

char	*check_line(char **str_store)
{
	char	*str;
	char	*ret;
	char	*temp;
	int		lenline;
	int		lenremainder;

	if (!*str_store[0])
	{
		free_mem(str_store);
		return (NULL);
	}
	str = ft_strchr(*str_store, '\n');
	if (str)
		lenremainder = ft_strlen(str + 1);
	else
		lenremainder = 0;
	lenline = ft_strlen(*str_store) - lenremainder;
	temp = *str_store;
	ret = ft_substr(temp, 0, lenline);
	*str_store = ft_substr(temp, lenline, lenremainder);
	free(temp);
	return (ret);
}

char	*read_buffer(int fd, char *str_store)
{
	int		chread;
	char	*buff;
	char	*temp;
	int		newline;

	newline = 0;
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buff == NULL)
		return (NULL);
	chread = 1;
	while (chread != 0 && (newline != 1))
	{
		chread = read(fd, buff, BUFFER_SIZE);
		if (chread == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[chread] = '\0';
		if (ft_strchr(buff, '\n'))
			newline = 1;
		if (!str_store)
			str_store = ft_strdup("");
		temp = str_store;
		str_store = ft_strjoin(temp, buff);
		free(temp);
	}
	free_mem(&buff);
	return (str_store);
}

char	*get_next_line(int fd)
{
	static char	*str_store;
	char		*output;

	if (fd < 0)
		return (NULL);
	str_store = read_buffer(fd, str_store);
	if (!str_store)
		return (NULL);
	output = check_line(&str_store);
	return (output);
}
