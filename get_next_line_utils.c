/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theonewhoknew <theonewhoknew@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:07:42 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/05/12 21:07:50 by theonewhokn      ###   ########.fr       */
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

size_t	ft_strchr(const char *s, int c, int n)
{	
	int			i;

	i = 0;
	if (!s)
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
	tmp = (char *)malloc(sizeof (char) * (ft_strlen(s1) + 1));
	if (!tmp)
		return (NULL);
	ft_strlcpy(tmp, s1, n + 1, 0);
	return (tmp);
}

char	*ft_strjoin(char *tmp, char *buf, size_t n)
{
	size_t		len;
	char		*join;
	int			i;
	int			j;

	j = 0;
	i = 0;
	len = 0;
	if (tmp == NULL || tmp == 0)
		return (ft_strdup(buf, n, tmp));
	len = n + ft_strlen(tmp);
	join = (char *)malloc(sizeof (char) * (len + 1));
	if (!join)
		return (NULL);
	while (tmp[j])
		join[i++] = tmp[j++];
	while (n)
	{
		join[i++] = *buf++;
		n--;
	}
	free (tmp);
	tmp = NULL;
	join[i] = '\0';
	return (join);
}
