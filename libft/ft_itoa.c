/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucorrei <lucorrei@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:56:45 by lucorrei          #+#    #+#             */
/*   Updated: 2025/04/16 14:15:58 by lucorrei         ###   ########.fr       */
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
		nn *= -1;
		res++;
	}
	while (nn)
	{
		res ++;
		nn /= 10;
	}
	return (res);
}

static void	_write_recursive(char **to_write, long nbr)
{
	char	*writer;

	writer = *to_write;
	if (nbr < 10)
	{
		*writer = nbr + '0';
		return ;
	}
	*writer = nbr % 10 + '0';
	nbr /= 10;
	writer--;
	_write_recursive(&writer, nbr);
}

char	*ft_itoa(int n)
{
	long	nn;
	int		size;
	int		sign;
	char	*res;
	char	*to_write;

	nn = n;
	size = _get_size(nn);
	sign = (nn >= 0) - (nn < 0);
	res = ft_calloc(size, 1);
	if (!res)
		return (NULL);
	nn *= sign;
	if (sign == -1)
	{
		res[0] = '-';
	}
	res[size - 1] = 0;
	to_write = res + size - 2;
	_write_recursive(&to_write, nn);
	return (res);
}
/*int	main(int argc, char **argv)
{
	char	*tester;

	if (argc != 2)
	{
		write(1, "provide an int as argument\n", 27);
		return (1);
 
	tester = ft_itoa(0);
	write(1, "Got: ", 5);
	write(1, tester, ft_strlen(tester));
	write(1, "\n", 1);
	free(tester);
	return (0);
}*/
