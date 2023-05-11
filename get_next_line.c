/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:07:25 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/05/11 11:28:23 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char	*remove_string(char *tmp, char c, int ret)
{
	int		len;
	char	*new_tmp;

	len = 0;
	len = ft_strchr(tmp, c);
	new_tmp = (char *)malloc(sizeof (char) * (ret - len + 1));
	ft_strlcpy(new_tmp, tmp, ret - len + 1, len);
	free (tmp);
	return (new_tmp);
}

char	*create_string(char *tmp, char c)
{
	size_t	len;
	char	*string;

	len = 0;
	len = ft_strchr(tmp, c);
	string = (char *)malloc(sizeof (char) * (len + 1));
	ft_strlcpy(string, tmp, len + 1, 0);
	return (string);
}

char	*create_nullstring(char *tmp, char c)
{
	size_t	len;
	char	*string;

	len = 0;
	len = ft_strchr(tmp, c);
	string = (char *)malloc(sizeof (char) * (len));
	ft_strlcpy(string, tmp, len, 0);
	free (tmp);
	tmp = NULL;
	return (string);
}

char	*get_next_line(int fd)
{	
	int			ret;
	char		buf[BUFFER_SIZE];
	static char	*tmp;
	char		*line;

	tmp = NULL;
	while (1)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret > 0)
			tmp = ft_strjoin(tmp, buf);
		else if ((ret == 0 && tmp == NULL) || ret == -1)
			return (NULL);
		if (ft_strchr(tmp, '\n') != 0)
		{	
			line = create_string(tmp, '\n');
			tmp = remove_string(tmp, '\n', ret);
			return (line);
		}
		else if (ft_strchr(tmp, '\0') != 0)
			return (create_nullstring(tmp, '\0'));
	}	
}
/*
int main(void)
{   
    char *line;
	int fd;

	fd = open("text.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
}
*/