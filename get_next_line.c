/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theonewhoknew <theonewhoknew@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:07:25 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/05/11 18:57:19 by theonewhokn      ###   ########.fr       */
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
		ft_memset(buf, 0, ret);
		//printf("FUNCTION IS CALLED\n");
		//printf("tmp buf before everything is: %s\n", tmp);
		if (ft_strchr(tmp, '\n', ft_strlen(tmp)) != 0)
		{	
		//	printf("entra en tmp directamente sin leer\n");
			line = create_string(tmp, '\n', ret);
		//	printf("new line is: %s\n", line);
			tmp = remove_string(tmp, '\n', ret);
		//	printf("new tmp after line is: %s\n", tmp);
			return (line);
		}
		//printf("read buf before %s\n", buf);
		ret = read(fd, buf, BUFFER_SIZE);
		//printf("Se leen %d bytes\n", ret);
		//printf("read buf after %s\n", buf);
		if ((ret == 0 && ft_strlen(tmp) == 0) || ret == -1)
			return (NULL);
		if (ret == 0 && ft_strlen(tmp) > 0)
		{	
			//printf("entra porque ya no hay newline, hay algunas letras junto a un null\n");
			//printf("tmp buf is %s\n", tmp);
			line = create_nullstring(tmp);
			//printf("new line is: %s\n", line);
			//printf("new tmp after line is: %s\n", tmp);
			return (line);
		}
		if (ft_strchr(buf, '\n', ret) != 0)
		{
			//printf("entra hay newline en el buffer\n");
			tmp = ft_strjoin(tmp, buf, ret);
			//printf("tmp buf is: %s\n", tmp);
			line = create_string(tmp, '\n', ret);
			//printf("new line is: %s\n", line);
			tmp = remove_string(tmp, '\n', ret);
			//printf("new tmp after line is: %s\n", tmp);
			return (line);
		}
		else
		{
			//printf("vuelve a loopear");
			tmp = ft_strjoin(tmp, buf, ret);
		}
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
}
