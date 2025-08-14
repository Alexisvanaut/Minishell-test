/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucorrei <lucorrei@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:53:42 by lucorrei          #+#    #+#             */
/*   Updated: 2025/04/14 16:10:08 by lucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*ss1;
	const unsigned char	*ss2;

	if (n == 0)
		return (0);
	ss1 = (const unsigned char *) s1;
	ss2 = (const unsigned char *) s2;
	while (*ss1 && *ss1 == *ss2 && n)
	{
		ss1++;
		ss2++;
		n--;
	}
	return (((int)*ss1 - (int)*ss2) * (n != 0));
}

int	ft_strcmp(const char *s1, const char *s2)
{
	const unsigned char	*ss1;
	const unsigned char	*ss2;

	if (!s1 || !s2)
		return (0);
	ss1 = (const unsigned char *) s1;
	ss2 = (const unsigned char *) s2;
	while (*ss2 && *ss1 && *ss1 == *ss2)
	{
		ss1++;
		ss2++;
	}
	return (((int)*ss1 - (int)*ss2));
}
