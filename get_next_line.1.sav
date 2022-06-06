#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

char	check_buffer(char *buff)
{
	int	i;

	i = 0;
	if (buff[i] == '\n')
		return ('N');
	else if (buff[i] == '\0')
		return ('E');
	while(i < BUFFER_SIZE)
	{
		if (buff[i] == '\n')
			return ('L');
		i++;
	}
	return ('B');
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
	int				textlen;
	int				space;
	char			flag;

	space = BUFFER_SIZE;
	bzero(buff, space);
	textlen = read(fd, buff, BUFFER_SIZE);
	flag = check_buffer(buff);
	printf("Flag = %c, Textlen = %d\n", flag, textlen);
	if (flag == 'B') //text > buffer size
		save_buffer(buff);
	else if (flag == 'E') //EOF reached
		return (NULL);	
	else if (flag == 'N')
	{
		bzero(buff,space);
		memset(buff, '\n', 1);
	}
//	else if (flag == 'L')

	return (buff);
}
