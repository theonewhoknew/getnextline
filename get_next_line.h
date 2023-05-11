/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:08:18 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/05/11 11:30:48 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>

size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *tmp, char *buf);
size_t	ft_strchr(const char *s, int c);
size_t	ft_strlcpy(char *dst, const char *src,
			size_t dstsize, unsigned int start);
char	*ft_strdup(const char *s1);
char	*remove_string(char *tmp, char c, int ret);
char	*create_string(char *tmp, char c);
char	*create_nullstring(char *tmp, char c);
char	*get_next_line(int fd);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

#endif
