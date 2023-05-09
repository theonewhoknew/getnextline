#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 10


char 	*get_next_line(int fd);
int		check_nl(char *buf, int bytes);
char 	*ft_strcpy(char *dst, char *buf, int i);
char *next(char *buf, int bytes);

# endif