/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucorrei <lucorrei@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:41:16 by lucorrei          #+#    #+#             */
/*   Updated: 2025/04/16 12:17:09 by lucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*temp_dest;
	unsigned char		*temp_src;
	size_t				i;

	if (!dest && !src)
		return (NULL);
	temp_dest = (unsigned char *) dest;
	temp_src = (unsigned char *) src;
	i = (src <= dest) * n;
	if (i)
	{
		while (i > 0)
		{
			i--;
			temp_dest[i] = temp_src[i];
		}
	}
	else
	{
		while (++i <= n)
			temp_dest[i - 1] = temp_src[i - 1];
	}
	return (dest);
}
/*
int	main(void)
{
	char s1[10] = "0123456789";
	char *s2 = s1 + 3;

	ft_putendl_fd(ft_memmove(s2, s1, 5), 1);
	return (0);
}*/
