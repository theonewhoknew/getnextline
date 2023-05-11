/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theonewhoknew <theonewhoknew@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:07:42 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/05/11 17:24:13 by theonewhokn      ###   ########.fr       */
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
	while (*s)
	{
		c++;
		s++;
	}
	return (c);
}

size_t	ft_strlcpy(char *dst, const char *src,
			size_t dstsize, unsigned int start)
{
	unsigned int	i;
	unsigned int	c;
	unsigned int	j;

	c = 0;
	i = start;
	j = 0;
	while (src[c] != '\0')
		++c;
	if (dstsize != 0)
	{
		while (src[i] != '\0' && j < (dstsize - 1))
		{
			dst[j] = src[i];
			i++;
			j++;
		}
		dst[j] = '\0';
	}
	return (c);
}

size_t	ft_strchr(const char *s, int c, int ret)
{	
	int			n;

	n = 0;
	while (n < ret)
	{
		if (s[n] == (char)c)
			return (n + 1);
		n++;
	}
	return (0);
}

char	*ft_strdup(const char *s1, int ret)
{
	char	*dup;

	dup = (char *)malloc(sizeof (char) * (ft_strlen(s1) + 1));
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, s1, ret + 1, 0);
	return (dup);
}

char	*ft_strjoin(char *tmp, char *buf, int ret)
{
	size_t		len;
	char		*join;
	int			i;

	i = 0;
	len = 0;
	if (tmp == NULL)
		return (ft_strdup(buf, ret));
	len = ret + ft_strlen(tmp);
	join = (char *)malloc(sizeof (char) * (len + 1));
	if (!join)
		return (NULL);
	while (*tmp)
	{
		join[i++] = *tmp;
		tmp++;
	}
	while (ret)
	{
		join[i++] = *buf;
		buf++;
		ret--;
	}
	join[i] = '\0';
	return (join);
}
