/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucorrei <lucorrei@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:31:16 by lucorrei          #+#    #+#             */
/*   Updated: 2025/04/16 12:00:58 by lucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*temp_dst;
	char	*temp_src;

	if (!dest && !src)
		return (NULL);
	i = 0;
	temp_dst = (char *) dest;
	temp_src = (char *) src;
	while (i < n)
	{
		temp_dst[i] = temp_src[i];
		i++;
	}
	return (dest);
}
