/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlytvync <dlytvync@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 10:43:12 by dlytvync          #+#    #+#             */
/*   Updated: 2025/05/29 11:47:14 by dlytvync         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*gnl_buffer(int fd, char *stash)
{
	static char	buffer[BUFFER_SIZE];
	ssize_t		bytes_read;
	size_t		stash_len;
	char		*temp;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		stash_len = gnl_len_to_c(stash, '\0');
		temp = malloc(sizeof(char) * (stash_len + bytes_read + 1));
		if (!temp)
			return (gnl_free(&stash));
		gnl_memmove(temp, stash, stash_len);
		gnl_memmove(temp + stash_len, buffer, bytes_read);
		temp[stash_len + bytes_read] = '\0';
		free(stash);
		stash = temp;
		if (gnl_strchr(stash, '\n') != NULL || bytes_read < BUFFER_SIZE)
			break ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (bytes_read == -1)
		return (gnl_free(&stash));
	return (stash);
}

char	*gnl_line_parser(char *stash)
{
	size_t	size;
	char	*newline;
	char	*line;

	if (!stash)
		return (gnl_free(&stash));
	size = gnl_len_to_c(stash, '\n');
	newline = gnl_strchr(stash, '\n');
	if (newline)
		size += 1;
	line = malloc(sizeof(char) * (size + 1));
	if (!line)
		return (NULL);
	gnl_memmove(line, stash, size);
	line[size] = '\0';
	return (line);
}

char	*gnl_append(char *stash)
{
	char	*next_line;
	char	*line;
	size_t	stash_len;

	line = gnl_strchr(stash, '\n');
	if (!line)
		return (gnl_free(&stash));
	stash_len = gnl_len_to_c(line, '\0');
	next_line = malloc(sizeof(char) * (stash_len + 1));
	if (!next_line)
		return (gnl_free(&stash));
	gnl_memmove(next_line, line + 1, stash_len);
	free(stash);
	return (next_line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = gnl_buffer(fd, stash);
	if (!stash || *stash == '\0')
		return (gnl_free(&stash));
	line = gnl_line_parser(stash);
	if (!line)
		return (gnl_free(&stash));
	stash = gnl_append(stash);
	return (line);
}
