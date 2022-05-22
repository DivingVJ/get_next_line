#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

char	*fill_buffer(int fd)
{
	int		textlen;

	printf("Before Textlen %d Buff %s\n", textlen, buff);
	textlen = read(fd, buff, BUFFER_SIZE);
	printf("After Textlen %d Buff %s\n", textlen, buff);
	bzero(buff, space);
	return (buff);
}

char	*get_next_line(int fd)
{
	static char		buff[BUFFER_SIZE];
	int				textlen;
	int				space;

	space = BUFFER_SIZE;
	textlen = 1;
	printf("Text len, space %d %d\n", textlen, space);
	// approach - fill buffer output buffer, 
	// empty buffer fill buffer output buffer
	while (textlen > 0)
	{
		printf("Before Textlen %d Buff %s\n", textlen, buff);
		textlen = read(fd, buff, BUFFER_SIZE);
		printf("After Textlen %d Buff %s\n", textlen, buff);
		bzero(buff, space);
	}
	return (buff);
}
