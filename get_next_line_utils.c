/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:07:42 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/05/11 11:23:39 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>

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

	c = 0;
	i = start;
	while (src[c] != '\0')
		++c;
	if (dstsize != 0)
	{
		while (src[i] != '\0' && i < (dstsize - 1))
		{
			dst[i] = src[i];
			++i;
		}
		dst[i] = '\0';
	}
	return (c);
}

size_t	ft_strchr(const char *s, int c)
{	
	int			n;

	n = 0;
	while (s[n] != '\0')
	{
		if (s[n] == (char)c)
			return (n + 1);
		n++;
	}
	if (s[n] == '\0' && (char) c == 0)
		return (n + 1);
	return (0);
}

char	*ft_strdup(const char *s1)
{
	char	*dup;

	dup = (char *)malloc(sizeof (char) * (ft_strlen(s1) + 1));
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, s1, ft_strlen(s1) + 1, 0);
	return (dup);
}

char	*ft_strjoin(char *tmp, char *buf)
{
	size_t		len;
	char		*join;
	int			i;

	i = 0;
	len = 0;
	if (tmp == NULL)
		return (ft_strdup(buf));
	len = ft_strlen(buf) + ft_strlen(tmp);
	join = (char *)malloc(sizeof (char) * (len + 1));
	if (!join)
		return (NULL);
	while (*tmp)
	{
		join[i++] = *tmp;
		tmp++;
	}
	while (*buf)
	{
		join[i++] = *buf;
		buf++;
	}
	join[i] = '\0';
	free (tmp);
	return (join);
}
