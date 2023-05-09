#include "get_next_line.h"
#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char *get_next_line(int fd)
{	
	char *next_line;
	static char *later_line;
	char buf[BUFFER_SIZE];
	int bytes;

	bytes = 0;
    while((bytes = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		if (check_nl(buf, bytes))
			next_line = next(buf, bytes);
		
	}
	return (next_line);
}

int main(void)
{   
    char *line;
	int fd;

	fd = open("text.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
}