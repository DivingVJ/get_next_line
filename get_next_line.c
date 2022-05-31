#include "get_next_line.h"

/*char	*output_buffer(int start, int index)
{
	char	*output;
	int		textlen;



	textlen = start - index; //content to copy in buff

	output = (char *)malloc(textlen);
	if (output == NULL)
		return (NULL);
	memcpy(output,buff[index],textlen);//copies buff content to output
	return (output);//returns output
} */

void	check_buffer(char *output, char *str_store)
//check if buff is fully filled or contains \n or EOF using strchr
{
	char	*ptr; //ptr to newline location

	ptr = ft_strchr(str_store,'\n');
	printf("after strcr");
	if (ptr != 0)
	{
		printf("before substr");
		output = ft_substr(str_store, 0, (str_store - ptr));
		printf("after substr");
	}
	else
	{
		output = str_store;
	}
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
	int			index;
	char		*output; // output string to return 
	static char	*str_store; // place to store output to manipulate.
	/* str_store is static so will be accessible for subsequent fn call */

	index = 0;
	chread = 1; //seed value	
	buff = (char *)malloc(BUFFER_SIZE + 1); 
	if (buff == NULL)
		return (NULL);	
	if (fd < 0 || (read(fd,buff,0) == -1)) // read(count = 0) for error checking 
		return (NULL);

	while (read_buffer(fd, &buff, &chread) != 0)
	{
		str_store = buff;
		index = index + 1;
		printf("Cycle = %d Chars read = %d\n", index, chread);
		check_buffer(output, str_store);
		printf("Afer");
	}
	return (output);
}
