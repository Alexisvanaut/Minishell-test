/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_16.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucorrei <lucorrei@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:24:46 by lucorrei          #+#    #+#             */
/*   Updated: 2025/04/28 15:33:02 by lucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	_get_size(long nn)
{
	int	res;

	res = 1;
	if (nn == 0)
		return (2);
	if (nn < 0)
	{
		return (9);
	}
	while (nn)
	{
		res ++;
		nn /= 16;
	}
	return (res);
}

static void	_write_recursive(char *writer, long nbr)
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

char	*ft_itoa_16(int n)
{
	long	nn;
	int		size;
	char	*res;
	char	*to_write;

	nn = n;
	size = _get_size(nn);
	res = ft_calloc(size, 1);
	if (!res)
		return (NULL);
	if (nn < 0)
	{
		nn += 2L * 2147483648L;
	}
	res[size - 1] = 0;
	to_write = res + size - 2;
	_write_recursive(to_write, nn);
	return (res);
}
