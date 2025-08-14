/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucorrei <lucorrei@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 18:23:26 by lucorrei          #+#    #+#             */
/*   Updated: 2025/04/22 17:40:32 by lucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*exit_error(char **line, t_overlap *overlap)
{
	size_t	i;

	i = 0;
	free(*line);
	*line = NULL;
	while (i < BUFFER_SIZE)
		overlap->content[i++] = 0;
	overlap->size = 0;
	return (NULL);
}

t_overlap	*__store_overlap(t_overlap *overlap, char *line, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		overlap->content[i] = line[i];
		i++;
	}
	overlap->size = n;
	return (overlap);
}

char	*__cleanup(t_overlap *overlap, t_bytes *line, char *newline)
{
	size_t	ol_size;

	if (!newline)
	{
		overlap->size = 0;
	}
	else
	{
		ol_size = line->content + line->size - newline - 1;
		__store_overlap(overlap, newline + 1, ol_size);
		line->size -= ol_size;
	}
	if (line->size == 0 || !__realloc_bytes(line, "\0", line->size + 1))
		exit_error(&(line->content), overlap);
	return (line->content);
}

char	*get_next_line(int fd)
{
	static t_overlap	overlap;
	t_bytes				line;
	char				buffer[BUFFER_SIZE];
	ssize_t				bytes_read;

	line = (t_bytes){0, 0, 0};
	if (overlap.size)
		__realloc_bytes(&line, overlap.content, overlap.size);
	bytes_read = 0;
	if (read(fd, buffer, 0) == -1)
		return (exit_error(&line.content, &overlap));
	while (!__find_newline(&line))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (exit_error(&line.content, &overlap));
		if (bytes_read == 0)
			break ;
		if (!__append_bytes(&line, buffer, bytes_read))
			return (exit_error(&(line.content), &overlap));
	}
	overlap.content[0] = 0;
	return (__cleanup(&overlap, &line, __find_newline(&line)));
}
