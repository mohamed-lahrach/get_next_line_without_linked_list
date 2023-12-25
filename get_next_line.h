#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
int		ft_strchar(char *str, int c);
int		ft_strlen(char *str);
char	*strjoin(char *str, char *buffer);
char	*fill_str(char *str, int fd);
int		get_len_until_newline(char *str);
char	*next_line(char *str);
char	*reset_str(char *str);
char	*get_next_line(int fd);

#endif