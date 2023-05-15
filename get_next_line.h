/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theonewhoknew <theonewhoknew@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:08:18 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/05/13 09:38:43 by theonewhokn      ###   ########.fr       */
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
char	*ft_strdup(const char *s1, size_t n, char *tmp);
char	*remove_string(char *tmp, size_t n, char *buf, size_t bytes);
char	*create_string(char *tmp, char c, size_t n);
char	*create_nullstring(char *tmp, char *line);
char	*get_next_line(int fd);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

#endif
