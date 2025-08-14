/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucorrei <lucorrei@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 18:46:40 by lucorrei          #+#    #+#             */
/*   Updated: 2025/04/22 12:09:11 by lucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# if (BUFFER_SIZE <= 0 || BUFFER_SIZE >= 1000000)
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 80
# endif // BUFFER_SIZE

# include <unistd.h>
# include <stdlib.h>

typedef struct s_bytes
{
	size_t	size;
	size_t	capacity;
	char	*content;
}	t_bytes;

typedef struct s_overlap
{
	size_t	size;
	char	content[BUFFER_SIZE];
}	t_overlap;

char	*get_next_line(int fd);
t_bytes	*__realloc_bytes(t_bytes *dest, char *to_append, size_t total);
t_bytes	*__append_bytes(t_bytes *dest, char *to_append, size_t count);
char	*__find_newline(t_bytes *line);

#endif // GET_NEXT_LINE_H
