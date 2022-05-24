#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

char	*output_buffer(int start, int index)
{
	char	*output;
	int		textlen;



	textlen = start - index; //content to copy in buff

	output = (char *)malloc(textlen);
	if (output == NULL)
		return (NULL);
	memcpy(output,buff[index],textlen);//copies buff content to output
//	bzero(buff, textlen); //erase buff content
	return (output);//returns output
}
char	check_buffer(int chread)
//check if buff is fully filled or contains \n or EOF
{
	int	i;
	int	start;

	i = 0;
	start = 0;
	while(i < chread) //only iterate through chars read 
	{
		if (buff[i] == '\n') // newline
		{
			output_buffer(start, i);
			start = i;
		}
		else if (buff[i] == '\0') // EOF
		{
			output_buffer(start, i);
			start = i;
		}
		else //full buffer
		{
			output_buffer(start, i);
		}
		i++;
	}
	return ('B'); //what to return?
}

void	save_buffer(char *buff)
{
	printf("string %s", buff);
}

/*char	*fill_buffer(int fd)
{
	int		textlen;

	printf("Before Textlen %d Buff %s\n", textlen, buff);
	textlen = read(fd, buff, BUFFER_SIZE);
	printf("After Textlen %d Buff %s\n", textlen, buff);
	bzero(buff, space);
	return (buff);
} */

char	*get_next_line(int fd)
{
	static char		buff[BUFFER_SIZE];
	int				chread;
	int				space;
	int				index; //keeps track location of newline

	index = 0;
	space = BUFFER_SIZE;
	//check ptr value, if 0<ptr<buffersize, buffer has value sent to output_buffer function
	//if (index != 0)
	//	output_buffer(index);
	chread = 1; //seed value
	while (chread != 0)
	{
		chread = read(fd, buff, BUFFER_SIZE); // read into buff
		check_buffer(chread); // check buff for /n, EOF 
	}
	printf("Char read = %d\n", chread);

	return (buff);
}
