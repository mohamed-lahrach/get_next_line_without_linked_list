#include "get_next_line.h"

char	*fill_str(char *str, int fd)
{
	char	*buffer;
	int		bytes;

	bytes = 1;
	while (bytes != 0 && ft_strchar(str, '\n') != 1)
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (buffer == NULL)
			return (NULL);
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
			return (free(str), free(buffer), NULL);
		str = strjoin(str, buffer);
		if (str == NULL)
			return (free(str), NULL);
	}
	return (free(buffer), str);
}

char	*next_line(char *str)
{
	int		len_until_newline;
	char	*line;
	int		i;

	i = 0;
	len_until_newline = get_len_until_newline(str);
	line = malloc(len_until_newline + 1);
	if (line == NULL)
		return (NULL);
	while (str[i] != '\0' && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}
char	*reset_str(char *str)
{
	int		start;
	int		i;
	char	*rest_str;

	start = get_len_until_newline(str);
	rest_str = malloc(ft_strlen(str) - start + 1);
	if (rest_str == NULL)
		return (NULL);
	i = 0;
	while (str[start])
		rest_str[i++] = str[start++];
	rest_str[i] = '\0';
	free(str);
	return (rest_str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	str = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0)
	{
		return (NULL);
	}
	str = fill_str(str, fd);
	if (str == NULL)
		return (NULL);
	line = next_line(str);
	str = reset_str(str);
	return (line);
}

int	main(void)
{
	int fd;

	fd = open("file.txt", O_RDONLY);
	char *str = get_next_line(fd);
	// char *str2 = get_next_line(fd);
	// char *str3 = get_next_line(fd);
	// char *str4 = get_next_line(fd);
	// char *str5 = get_next_line(fd);
	// char *str6 = get_next_line(fd);
	// char *str7 = get_next_line(fd);

	printf("%s", str);
	// printf("%s", str2);
	// printf("%s", str3);
	// printf("%s", str4);
	// printf("%s", str5);
	// printf("%s", str6);
	// printf("%s", str7);

	free(str);
}