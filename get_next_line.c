/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theonewhoknew <theonewhoknew@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:07:25 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/05/12 21:08:07 by theonewhokn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	*ft_memset(void *b, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = b;
	i = 0;
	while (i < n)
	{
		ptr[i] = c;
		i++;
	}
	return (b);
}

char	*remove_string(char *tmp, size_t n, char *buf, size_t bytes)
{
	int		len;
	char	*new_tmp;

	len = 0;
	len = ft_strchr(tmp, '\n', ft_strlen(tmp));
	new_tmp = (char *)malloc(sizeof (char) * (n - len + 1));
	ft_strlcpy(new_tmp, tmp, n - len + 1, len);
	free (tmp);
	tmp = NULL;
	new_tmp = ft_strjoin(new_tmp, buf, bytes);
	return (new_tmp);
}

char	*create_string(char *tmp, char c, size_t n)
{
	size_t	len;
	char	*string;

	len = 0;
	len = ft_strchr(tmp, c, n);
	string = (char *)malloc(sizeof (char) * (len + 1));
	ft_strlcpy(string, tmp, len + 1, 0);
	return (string);
}

char	*create_nullstring(char *tmp, char *line)
{
	size_t	len;

	len = 0;
	len = ft_strlen(tmp);
	line = (char *)malloc(sizeof (char) * (len + 1));
	ft_strlcpy(line, tmp, len + 1, 0);
	ft_memset(tmp, 0, ft_strlen(tmp));
	return (line);
}

char	*get_next_line(int fd)
{	
	int				bytes;
	char			buf[BUFFER_SIZE];
	static char		*tmp;
	char			*line;

	line = NULL;
	while (1)
	{	
		bytes = read(fd, buf, BUFFER_SIZE);
		if ((bytes == 0 && ft_strlen(tmp) == 0)
			|| bytes == -1 || (bytes == 0 && tmp == NULL))
		{
			free (tmp);
			return (NULL);
		}
		if (ft_strchr(tmp, '\n', bytes) != 0)
		{	
			line = create_string(tmp, '\n', ft_strlen(tmp));
			tmp = remove_string(tmp, '\n', buf, bytes);
			return (line);
		}
		else if (bytes == 0 && ft_strlen(tmp) > 0)
			return (create_nullstring(tmp, line));
		tmp = ft_strjoin(tmp, buf, bytes);
	}
}
/*
int main(void)
{   
    char *line;
	int fd;

	fd = open("text.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free (line);
	}
}
*/
