/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlahrach <mlahrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 12:38:32 by aabdenou          #+#    #+#             */
/*   Updated: 2023/12/26 18:09:50 by mlahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_file_into_buffer(char *static_buffer, int fd)
{
	char	*read_buffer;
	int		read_count;

	read_count = 1;
	read_buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (read_buffer == NULL)
		return (NULL);
	while (read_count != 0 && find_char_in_string(static_buffer, '\n') != 1)
	{
		read_count = read(fd, read_buffer, BUFFER_SIZE);
		if (read_count == -1)
			return (free(static_buffer), free(read_buffer), NULL);
		read_buffer[read_count] = '\0';
		static_buffer = ft_strjoin(static_buffer, read_buffer);
		if (static_buffer == NULL)
			return (free(read_buffer), NULL);
	}
	return (free(read_buffer), static_buffer);
}

int	count_chars_until_newline(char *static_buffer)
{
	int	i;

	i = 0;
	while (static_buffer[i] && static_buffer[i] != '\n')
		i++;
	return (i);
}

char	*copy_until_newline(char *static_buffer)
{
	char	*substr_to_newline;
	int		i;
	int		j;

	i = count_chars_until_newline(static_buffer);
	j = 0;
	if (static_buffer[0] == '\0')
		return (NULL);
	if (static_buffer[i] == '\n')
		i++;
	substr_to_newline = malloc(i + 1);
	if (substr_to_newline == NULL)
		return (NULL);
	i = 0;
	while (static_buffer[i] && static_buffer[i] != '\n')
		substr_to_newline[j++] = static_buffer[i++];
	if (static_buffer[i] == '\n')
		substr_to_newline[j++] = '\n';
	substr_to_newline[j] = '\0';
	return (substr_to_newline);
}

char	*get_remaining_after_newline(char *static_buffer)
{
	char	*remaining_str;
	size_t	j;
	size_t	i;

	i = count_chars_until_newline(static_buffer);
	j = 0;
	if (static_buffer[i] == '\0')
	{
		free(static_buffer);
		return (NULL);
	}
	remaining_str = malloc(ft_strlen(static_buffer) - i + 1);
	if (remaining_str == NULL)
		return (NULL);
	if (static_buffer[i++] != '\n')
		i++;
	while (static_buffer[i] != '\0')
		remaining_str[j++] = static_buffer[i++];
	remaining_str[j] = '\0';
	free(static_buffer);
	return (remaining_str);
}

char	*get_next_line(int fd)
{
	static char	*static_buffer[OPEN_MAX];
	char		*current_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	static_buffer[fd] = read_file_into_buffer(static_buffer[fd], fd);
	if (static_buffer[fd] == NULL)
		return (NULL);
	current_line = copy_until_newline(static_buffer[fd]);
	static_buffer[fd] = get_remaining_after_newline(static_buffer[fd]);
	return (current_line);
}
