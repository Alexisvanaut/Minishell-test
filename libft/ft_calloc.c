/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucorrei <lucorrei@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:12:54 by lucorrei          #+#    #+#             */
/*   Updated: 2025/04/17 14:26:53 by lucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nemb, size_t size)
{
	unsigned char	*res;
	size_t			i;

	res = 0;
	res = (unsigned char *) malloc(nemb * size);
	if (!res)
		return (NULL);
	i = 0;
	while (i < nemb * size)
		res[i++] = 0;
	return (res);
}
