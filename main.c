#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

int	main (void)
{
	int		fd;
	char	*str;
	fd = open("text.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("String1 is %s", str);
	str = get_next_line(fd);
	printf("String2 is %s", str);
	str = get_next_line(fd);
	printf("String3 is %s", str);
	return (0);
}