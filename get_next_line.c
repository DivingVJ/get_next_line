#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>

/* File placeholder */
char    *get_next_line(int fd)
{
    static char    buff[20];
    size_t  num;

    num = sizeof(buff);
    read(fd, buff, num);

    return (buff);
}