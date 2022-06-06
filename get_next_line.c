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
//	printf("ret = %s\n", ret);
//edit flag incude \n in lenline
	*str_store = ft_substr(temp, lenline, lenremainder);
//	printf("new str_store= %s\n", *str_store);
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
//	if (read(fd,buff,0) == -1)
//		return (NULL);
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
		printf("Chread : Buff : store \n %d : %s : %s\n", chread, buff, str_store);			
		temp = str_store;
//		printf("temp= %s\n", temp);
		str_store = ft_strjoin(temp, buff);
//		printf("afterjoin %s\n", str_store);
		free(temp);		
	}
	free(buff);
//	buff = NULL; to check
//	printf("in %s\n", str_store);	
	return (str_store);
}

char	*get_next_line(int fd)
{
	static char	*str_store;
	char		*output;
	
	if (fd < 0) 
		return (NULL);
//	printf("previous str_store= %s\n", str_store);
	str_store = read_buffer(fd, str_store);
//	printf("after readbuff %s: %ld\n", str_store, ft_strlen(str_store));
	if (!str_store)
		return (NULL);
	output = check_line(&str_store);
	return (output);
}
// valgrind -s --track-origins=yes --tool=memcheck --leak-check=full --show-leak-kinds=all ./a.out 
// valgrind  --tool=memcheck --leak-check=full --show-leak-kinds=all ./a.out 