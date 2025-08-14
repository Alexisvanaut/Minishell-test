/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucorrei <lucorrei@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 14:30:50 by lucorrei          #+#    #+#             */
/*   Updated: 2025/07/04 14:30:54 by lucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <math.h>

static double	__decimal(char *str)
{
	int		i;
	double	res;

	res = 0;
	i = 0;
	while (ft_isdigit(*++str) && ++i)
	{
		res += ((*str) - '0') / (pow(10.0, i));
	}
	return (res);
}

/*
** string to double function
** no overflow protection
*/
double	ft_atod(char *str)
{
	double	res;
	double	sign;

	if (!str)
		return (0);
	sign = 1;
	res = 0;
	while (*str && ft_strchr("\t\n\v\f\r ", *str))
		str++;
	if (*str == '-' || *str == '+')
	{
		sign -= 2 * (*str == '-');
		str++;
	}
	while (ft_isdigit(*str))
	{
		res *= 10;
		res += *(str++) - '0';
	}
	if (*str == '.')
	{
		res += __decimal(str);
	}
	return (sign * res);
}
