/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:07:25 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/05/12 08:37:13 by dtome-pe         ###   ########.fr       */
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

char	*remove_string(char *tmp, char c, size_t ret)
{
	int		len;
	char	*new_tmp;

	len = 0;
	len = ft_strchr(tmp, c, ft_strlen(tmp));
	ret = ft_strlen(tmp);
	new_tmp = (char *)malloc(sizeof (char) * (ret - len + 1));
	ft_strlcpy(new_tmp, tmp, ret - len + 1, len);
	free (tmp);
	return (new_tmp);
}

char	*create_string(char *tmp, char c, int ret)
{
	size_t	len;
	char	*string;

	len = 0;
	ret = ft_strlen(tmp);
	len = ft_strchr(tmp, c, ret);
	string = (char *)malloc(sizeof (char) * (len + 1));
	ft_strlcpy(string, tmp, len + 1, 0);
	return (string);
}

char	*create_nullstring(char *tmp)
{
	size_t	len;
	char	*string;

	len = 0;
	len = ft_strlen(tmp);
	string = (char *)malloc(sizeof (char) * (len + 1));
	ft_strlcpy(string, tmp, len + 1, 0);
	ft_memset(tmp, 0, ft_strlen(tmp));
	return (string);
}

char	*get_next_line(int fd)
{	
	int			ret;
	char		buf[BUFFER_SIZE];
	static char	*tmp;
	char		*line;

	while (1)
	{	
		if (ft_strchr(tmp, '\n', ft_strlen(tmp)) != 0)
		{	
			line = create_string(tmp, '\n', ret);
			tmp = remove_string(tmp, '\n', ret);
			return (line);
		}
		ret = read(fd, buf, BUFFER_SIZE);
		if ((ret == 0 && ft_strlen(tmp) == 0) || ret == -1)
			return (NULL);
		if (ret == 0 && ft_strlen(tmp) > 0)
		{	
			line = create_nullstring(tmp);
			return (line);
		}
		if (ft_strchr(buf, '\n', ret) != 0)
		{
			tmp = ft_strjoin(tmp, buf, ret);
			line = create_string(tmp, '\n', ret);
			tmp = remove_string(tmp, '\n', ret);
			return (line);
		}
		else
			tmp = ft_strjoin(tmp, buf, ret);
	}
}
/*
int main(void)
{   
    char *line;
	int fd;

	fd = open("text.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
		printf("%s", line);
}
*/