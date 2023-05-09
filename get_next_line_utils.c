#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

char *next(char *buf, int bytes)
{
	int i;
	int j;
	char *line;
	int n;

	j = 0;
	i = 0;
	while (buf[i] != '\n')
		i++;
	line = (char *)malloc(sizeof (char) * (i + 2));
	while (j <= i)
	{
		line[j] = buf[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

int check_nl(char *buf, int bytes)
{
	int i;

	i = 0;
	while (i < (bytes - 1))
	{
		if (buf[i] == '\n')
			return (1);
	}
	return (0);
}