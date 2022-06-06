#include "get_next_line.h"

char	*check_line(char **str_store)
{
	char	*str;
	char	*ret;
	char	*temp;
	int		lenline;
	int		lenremainder;

	if (!*str_store[0])
	{
		return (NULL);
	}
	str = ft_strchr(*str_store, '\n');
	lenremainder = ft_strlen(str + 1);
	lenline = ft_strlen(*str_store) - lenremainder;
	printf("len= %d : %d\n", lenline, lenremainder);
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

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buff == NULL)
		return (NULL);
	chread = 1;
	while (chread != 0 && (!ft_strchr(buff, '\n')))
	{
		chread = read(fd, buff, BUFFER_SIZE);
		if (chread == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[chread] = '\0';
		if (!str_store)
			str_store = ft_strdup("");
		temp = str_store;
		str_store = ft_strjoin(temp, buff);
		free(temp);
	}
	free(buff);
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
/* valgrind -s --track-origins=yes --tool=memcheck --leak-check=full --show-leak-kinds=all ./a.out 
 valgrind  --tool=memcheck --leak-check=full --show-leak-kinds=all ./a.out */