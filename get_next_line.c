/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theonewhoknew <theonewhoknew@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:07:25 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/05/16 17:26:54 by theonewhokn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char	*ft_free(char *tmp)
{
	free (tmp);
	tmp = NULL;
	return (NULL);
}

char	*remove_string(char *tmp)
{
	size_t		len;
	char		*new_tmp;
	size_t		n;

	len = ft_strchr(tmp, '\n', ft_strlen(tmp));
	n = ft_strlen(tmp);
	if (len == n)
	{
		free (tmp);
		tmp = NULL;
		return (tmp);
	}
	else
	{
		new_tmp = (char *)malloc(sizeof (char) * (n - len + 1));
		if (!new_tmp)
			return (ft_free(tmp));
		ft_strlcpy(new_tmp, tmp, n - len + 1, len);
		free (tmp);
		tmp = NULL;
	}
	return (new_tmp);
}

char	*create_string(char *tmp, char c, size_t n)
{
	size_t	len;
	char	*string;

	len = 0;
	len = ft_strchr(tmp, c, n);
	string = (char *)malloc(sizeof (char) * (len + 1));
	if (!string)
	{	
		free (string);
		string = NULL;
		return (NULL);
	}
	ft_strlcpy(string, tmp, len + 1, 0);
	return (string);
}

char	*create_nullstring(char **tmp, char *line)
{
	size_t	len;

	if (!*tmp)
		return (NULL);
	len = 0;
	len = ft_strlen(*tmp);
	line = (char *)malloc(sizeof (char) * (len + 1));
	if (!line)
	{	
		free (line);
		line = NULL;
		free (*tmp);
		*tmp = NULL;
		return (NULL);
	}
	ft_strlcpy(line, *tmp, len + 1, 0);
	free (*tmp);
	*tmp = NULL;
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
		if ((bytes == 0 && tmp == NULL) || bytes == -1)
			return (tmp = ft_free(tmp));
		tmp = ft_strjoin(tmp, buf, bytes);
		if (ft_strchr(tmp, '\n', ft_strlen(tmp)) != 0)
		{
			line = create_string(tmp, '\n', ft_strlen(tmp));
			if (!line)
				tmp = ft_free(tmp);
			tmp = remove_string(tmp);
			return (line);
		}
		else if (bytes == 0 && ft_strlen(tmp) > 0)
			return (line = create_nullstring(&tmp, line));
	}
}
/*
int main(void)
{   
    char *line;
	int fd;
	char c = 0;

	fd = open("1char.txt", O_RDONLY);
	
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free (line);
	} 

	line = get_next_line(fd);
	printf("%s", line);
	//line = get_next_line(fd);
	//printf("%s", line);

}
*/

