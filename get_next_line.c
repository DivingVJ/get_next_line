#include "get_next_line.h"

void	check_buffer(char **str_store)
//check if buff is fully filled or contains \n or EOF using strchr
{
	int		length;

	length = ft_linelen(*str_store);
	printf("Len = %d", length);
/*	if (*ptr != '\0')
	{
		*output = ft_substr(*str_store, 0, length);
	}
	else
	{
		output = str_store;
	} */
}

int	read_buffer(int fd, char **buff, int *chread)
{
	*chread = read(fd, *buff, BUFFER_SIZE); 
	buff[*chread] = '\0';
	return (*chread);
}

char	*get_next_line(int fd)
{
	char		*buff;
	int			chread;
//	char		*output; // output string to return 
	static char	*str_store; // place to store output to manipulate.
	/* str_store is static so will be accessible for subsequent fn call */

	chread = 1; //seed value	
	buff = (char *)malloc(BUFFER_SIZE + 1); 
	if (buff == NULL)
		return (NULL);	
	if (fd < 0 || (read(fd,buff,0) == -1)) // read(count = 0) for error checking 
		return (NULL);

	while (read_buffer(fd, &buff, &chread) != 0)
	{
		str_store = buff;
		check_buffer(&str_store);
		printf("Afer");
	}
	return (str_store);
}
