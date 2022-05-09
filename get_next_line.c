#include "get_next_line.h"
#include <stdio.h>

/* File placeholder */
char    *get_next_line(int fd)
{
    static char    buff[BUFFER_SIZE];
    int		len;
	size_t  num;

    num = sizeof(buff);
    len = read(fd, buff, num);
	if (len == -1)
	{
		printf("Error");
		return (0);
	}
    return (buff);
}