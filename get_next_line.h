/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:08:18 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/05/12 12:21:17 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>

size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *tmp, char *buf, size_t n);
size_t	ft_strchr(const char *s, int c, int n);
size_t	ft_strlcpy(char *dst, const char *src,
			size_t dstsize, unsigned int start);
char	*ft_strdup(const char *s1, size_t n);
char	*remove_string(char *tmp, char c, size_t n);
char	*create_string(char *tmp, char c, size_t n);
char	*create_nullstring(char *tmp);
char	*get_next_line(int fd);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

#endif
