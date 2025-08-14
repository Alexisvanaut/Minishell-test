/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_16.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucorrei <lucorrei@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:29:38 by lucorrei          #+#    #+#             */
/*   Updated: 2025/04/28 16:05:10 by lucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	_get_size(size_t nn)
{
	int	res;

	res = 1;
	if (nn == 0)
		return (2);
	while (nn)
	{
		res ++;
		nn /= 16;
	}
	return (res);
}

static void	_write_recursive(char *writer, size_t nbr)
{
	char	*base;

	base = "0123456789abcdef";
	if (nbr < 16)
	{
		*writer = *(base + nbr);
		return ;
	}
	*writer = *(nbr % 16 + base);
	nbr /= 16;
	writer--;
	_write_recursive(writer, nbr);
}

char	*ft_ultoa_16(size_t nn)
{
	int		size;
	char	*res;
	char	*to_write;

	size = _get_size(nn);
	res = ft_calloc(size, 1);
	if (!res)
		return (NULL);
	res[size - 1] = 0;
	to_write = res + size - 2;
	_write_recursive(to_write, nn);
	return (res);
}
