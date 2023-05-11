/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theonewhoknew <theonewhoknew@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:07:25 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/05/11 17:26:16 by theonewhokn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

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

char	*create_nullstring(char *tmp, char c, int ret)
{
	size_t	len;
	char	*string;

	len = 0;
	len = ft_strchr(tmp, c, ret);
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
		//if (ret > 0)
		//	
		if ((ret == 0 && tmp == NULL) || ret == -1)
			return (NULL);
		if (ft_strchr(buf, '\n', ret) != 0)
		{
			//printf("entra en newline\n");
			tmp = ft_strjoin(tmp, buf, ret);
			//printf("tmp buf is: %s\n", tmp);
			line = create_string(tmp, '\n', ret);
			//printf("new line is: %s\n", line);
			tmp = remove_string(tmp, '\n', ret);
			//printf("new tmp after line is: %s\n", tmp);
			return (line);
		}
		else if (ft_strchr(buf, '\0', ret) != 0)
		{
			tmp = ft_strjoin(tmp, buf, ret);
			return (create_nullstring(tmp, '\0', ret));
		}
		tmp = ft_strjoin(tmp, buf, ret);
	}
}

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
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
}
