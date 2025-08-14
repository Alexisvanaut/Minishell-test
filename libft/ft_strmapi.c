/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucorrei <lucorrei@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:29:02 by lucorrei          #+#    #+#             */
/*   Updated: 2025/04/15 14:38:18 by lucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	unsigned int	i;
	unsigned int	size;

	if (!s)
		return (NULL);
	if (!f)
		return (NULL);
	size = ft_strlen(s) + 1;
	res = 0;
	res = ft_calloc(size, 1);
	if (!res)
		return (NULL);
	i = 0;
	while (i < size - 1)
	{
		res[i] = (*f)(i, s[i]);
		i++;
	}
	return (res);
}
