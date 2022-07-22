/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbishop- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 12:39:25 by mbishop-          #+#    #+#             */
/*   Updated: 2022/02/07 12:42:43 by mbishop-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static char	*read_and_append(int fd, char *buffer, char *remainder)
{
	int		bytes_read;
	char	*temp;

	bytes_read = 1;
	while (bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (0);
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		if (!remainder)
			remainder = ft_strdup("");
		temp = remainder;
		remainder = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (ft_strchr (buffer, '\n'))
			break ;
	}
	return (remainder);
}

static char	*update_new_line(char *line)
{
	size_t	idx;
	char	*remainder;

	idx = 0;
	while (line[idx] != '\n' && line[idx] != '\0')
		idx++;
	if (line[idx] == '\0' || line[1] == '\0')
		return (0);
	remainder = ft_substr(line, idx + 1, ft_strlen(line) - idx);
	if (*remainder == '\0')
	{
		free(remainder);
		remainder = NULL;
	}
	line[idx + 1] = '\0';
	return (remainder);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*remainder;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	line = read_and_append(fd, buffer, remainder);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	remainder = update_new_line(line);
	return (line);
}
