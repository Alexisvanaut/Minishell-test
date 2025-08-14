/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucorrei <lucorrei@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:53:42 by lucorrei          #+#    #+#             */
/*   Updated: 2025/04/16 18:10:36 by lucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	c %= 256;
	while (*s)
	{
		if (*s == c)
			return ((char *) s);
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (NULL);
}
/*
int	main(int argc, char **argv)
{
	if (argc != 3)
		return (1);
	ft_putendl_fd(ft_strchr(argv[1], *argv[2]), 1);
	return (0);
}*/
