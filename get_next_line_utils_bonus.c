/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlahrach <mlahrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:08:18 by aabdenou          #+#    #+#             */
/*   Updated: 2023/12/26 18:18:13 by mlahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	find_char_in_string(const char *s, int c)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (1);
		i++;
	}
	if ((char)c == 0)
		return (1);
	return (0);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *str, char *buffer)
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
	free(str);
	return (joined_str);
}
