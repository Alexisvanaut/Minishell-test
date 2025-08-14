/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucorrei <lucorrei@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 13:49:45 by lucorrei          #+#    #+#             */
/*   Updated: 2025/04/16 19:18:24 by lucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	_get_size(char const *s, unsigned int start, size_t cp)
{
	size_t	len;

	len = ft_strlen(s);
	if (start >= len)
		return (1);
	if (len - start > cp)
		return (cp + 1);
	else
		return (len - start + 1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		to_alloc;
	char	*res;

	to_alloc = _get_size(s, start, len);
	res = 0;
	res = ft_calloc(to_alloc, 1);
	if (!res)
		return (NULL);
	if (to_alloc != 1)
		ft_strlcpy(res, s + start, to_alloc);
	return (res);
}
/*
int main(int argc, char **argv)
{
	unsigned int	start;
	size_t			len;
	char const		*s;

	if (argc != 4)
	{
		ft_putendl_fd("Usage: string, start index, length", 1);
		return (1);
	}
	s = argv[1];
	start = (unsigned int) ft_atoi(argv[2]);
	len = ft_atoi(argv[3]);
	ft_putendl_fd(ft_substr(s, start, len), 1);
	return (0);
}*/
