/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucorrei <lucorrei@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:04:35 by lucorrei          #+#    #+#             */
/*   Updated: 2025/04/28 14:12:28 by lucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	_get_size(unsigned long nn)
{
	int	res;

	res = 1;
	if (nn == 0)
		return (2);
	while (nn)
	{
		res++;
		nn /= 10;
	}
	return (res);
}

static void	_write_recursive(char *writer, long nbr)
{
	if (nbr < 10)
	{
		*writer = nbr + '0';
		return ;
	}
	*writer = nbr % 10 + '0';
	nbr /= 10;
	writer--;
	_write_recursive(writer, nbr);
}

char	*ft_uitoa(unsigned int n)
{
	unsigned long	nn;
	int				size;
	char			*res;
	char			*to_write;

	nn = n;
	size = _get_size(nn);
	res = ft_calloc(size, 1);
	if (!res)
		return (NULL);
	res[size - 1] = 0;
	to_write = res + size - 2;
	_write_recursive(to_write, nn);
	return (res);
}
