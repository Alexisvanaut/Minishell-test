/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucorrei <lucorrei@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:33:33 by lucorrei          #+#    #+#             */
/*   Updated: 2025/04/22 16:46:51 by lucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

t_bytes	*__realloc_bytes(t_bytes *dest, char *to_append, size_t total)
{
	size_t	i;
	char	*new;

	new = 0;
	new = malloc(dest->capacity + BUFFER_SIZE);
	if (!new)
		return (NULL);
	i = -1;
	while (++i < dest->size)
		new[i] = dest->content[i];
	while (i < total)
		new[i++] = *to_append++;
	if (dest->content)
		free(dest->content);
	dest->content = new;
	dest->size = total;
	dest->capacity += BUFFER_SIZE;
	return (dest);
}

t_bytes	*__append_bytes(t_bytes *dest, char *to_append, size_t count)
{
	size_t	total;
	size_t	i;

	total = dest->size + count;
	i = -1;
	if (total >= dest->capacity)
		return (__realloc_bytes(dest, to_append, total));
	else
	{
		while (++i < count)
			*(dest->content + dest->size + i) = *to_append++;
	}
	dest->size = total;
	return (dest);
}

char	*__find_newline(t_bytes *line)
{
	size_t	i;

	if (!line || !line->content)
		return (NULL);
	else
	{
		i = 0;
		while (i < line->size)
		{
			if (line->content[i] == '\n')
				return (line->content + i);
			i++;
		}
		return (NULL);
	}
}
