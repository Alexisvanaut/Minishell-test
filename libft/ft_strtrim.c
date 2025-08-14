/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucorrei <lucorrei@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:19:00 by lucorrei          #+#    #+#             */
/*   Updated: 2025/04/17 13:55:24 by lucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	_char_in_string(char c, const char *s)
{
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	beg;
	unsigned int	end;
	unsigned int	len;
	char			*res;

	len = ft_strlen(s1);
	beg = 0;
	while (_char_in_string(s1[beg], set) && \
			beg < len)
		beg++;
	end = 0;
	while (beg != len \
			&& *s1 \
			&& _char_in_string(s1[len - end - 1], set))
		end++;
	res = 0;
	res = ft_calloc(len - beg - end + 1, 1);
	if (!res)
		return (NULL);
	ft_strlcpy(res, s1 + beg, len - beg - end + 1);
	return (res);
}
/*
int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_putendl_fd("Expected 2 args : 1.to_trim 2.charset", 1);
		return (1);
	}
	ft_putendl_fd("Size :", 1);
	ft_putnbr_fd(ft_strlen(ft_strtrim(argv[1], argv[2])), 1);
	ft_putendl_fd("\nAns", 1);
	ft_putendl_fd(ft_strtrim(argv[1], argv[2]), 1);
	return (0);
}*/
