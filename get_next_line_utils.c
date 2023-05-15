/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:07:42 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/05/15 14:10:34 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	unsigned int	c;

	c = 0;
	if (!s)
		return (0);
	while (s[c])
		c++;
	return (c);
}

void	ft_strlcpy(char *dst, const char *src,
			size_t dstsize, unsigned int start)
{
	unsigned int	i;
	unsigned int	c;
	unsigned int	j;

	c = 0;
	i = start;
	j = 0;
	if (dstsize != 0)
	{
		while (j < (dstsize - 1))
		{
			dst[j] = src[i];
			i++;
			j++;
		}
	}
	dst[j] = '\0';
}

size_t	ft_strchr(const char *s, int c, int n)
{	
	int			i;

	i = 0;
	if (!s || n == 0)
		return (0);
	while (i < n)
	{
		if (s[i] == (char)c)
			return (i + 1);
		i++;
	}
	return (0);
}

char	*ft_strdup(const char *s1, size_t n, char *tmp)
{	
	/* if (tmp)
	{
		free (tmp);
		tmp = NULL;
	} */
	tmp = (char *)malloc(sizeof (char) * (n + 1));
	if (!tmp)
	{	
		free (tmp);
		tmp = NULL;
		return (NULL);
	}
	ft_strlcpy(tmp, s1, n + 1, 0);
	ft_memset((char *) s1, '\0', n);
	//free (tmp);
	//tmp = NULL;
	return (tmp);
}

char	*ft_strjoin(char *tmp, char *buf, size_t n)
{
	char		*join;
	int			i;
	int			j;

	j = 0;
	i = 0;
	if (!tmp || tmp == 0)
	{
		join = ft_strdup((const char *) buf, n, tmp);
		return (join);
	}
	join = (char *)malloc(sizeof (char) * (ft_strlen(tmp) + n + 1));
	if (!join)
		return (NULL);
	while (tmp[j])
		join[i++] = tmp[j++];
	j = 0;
	while (n)
	{
		join[i++] = buf[j++];
		n--;
	}
	join[i] = '\0';
	ft_memset(buf, '\0', n);
	free (tmp);
	tmp = NULL;
	return (join);
}
