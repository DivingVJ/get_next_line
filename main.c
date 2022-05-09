#include "get_next_line.h"
#include <stdio.h>

int	main (void)
{
	int		fd;
	char	*str;
	fd = open("text.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("String is %s", str);
	return (0);
}