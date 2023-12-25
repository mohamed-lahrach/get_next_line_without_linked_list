#include "get_next_line.h"

int	ft_strchar(char *str, int c)
{
	if (str == NULL)
		return (0);
	while (*str)
	{
		if (*str == (char)c)
			return (1);
		str++;
	}
	return (0);
}
int	ft_strlen(char *str)
{
	int	len;

	if (str == NULL)
		return (0);
	len = 0;
	while (*(str + len))
		len++;
	return (len);
}
char	*strjoin(char *str, char *buffer)
{
	char	*joined_str;
	int		i;

	i = 0;
	joined_str = malloc(ft_strlen(str) + ft_strlen(buffer) + 1);
	if (joined_str == NULL)
		return (NULL);
	while (str != NULL && *(str + i))
	{
		joined_str[i] = str[i];
		i++;
	}
	while (buffer != NULL && *buffer)
	{
		joined_str[i] = *buffer;
		i++;
		buffer++;
	}
	joined_str[i] = '\0';
	return (joined_str);
}

int	get_len_until_newline(char *str)
{
	int len;

	len = 0;
	while (str[len])
	{
		if (str[len] == '\n')
		{
			len++;
			return (len);
		}
		len++;
	}
	return (len);
}