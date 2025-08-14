/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucorrei <lucorrei@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:24:45 by lucorrei          #+#    #+#             */
/*   Updated: 2025/05/10 18:11:42 by lucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_toupper_iter(unsigned int i, char *c)
{
	if (!c)
		return ;
	(void) i;
	*c = ft_toupper(*c);
}

char	*prepend(short formatting)
{
	char	*to_prepend;

	to_prepend = 0;
	if (HEX_SIGNAL & formatting)
	{
		to_prepend = ft_strjoin("0x", to_prepend);
	}
	if (IS_NEG & formatting)
	{
		to_prepend = ft_strjoin_free_second("-", to_prepend);
	}
	else if (NUMBER_PLUS & formatting)
	{
		to_prepend = ft_strjoin_free_second("+", to_prepend);
	}
	else if (NUMBER_SPACE & formatting)
	{
		to_prepend = ft_strjoin_free_second(" ", to_prepend);
	}
	return (to_prepend);
}

char	*align_left(t_format *item)
{
	char	*res;
	char	filler;
	int		size;

	size = item->min + 1 - ft_strlen(item->string);
	if (ZERO_PAD & item->formatting)
		filler = '0';
	else
		filler = ' ';
	res = 0;
	res = ft_calloc(size, 1);
	if (!res)
	{
		free(item->string);
		return (NULL);
	}
	ft_memset(res, filler, size - 1);
	return (ft_strjoin_free_both(item->string, res));
}

char	*align_right(t_format *item)
{
	char	*res;
	char	filler;
	int		size;

	size = item->min + 1 - ft_strlen(item->string);
	if (ZERO_PAD & item->formatting)
		filler = '0';
	else
		filler = ' ';
	res = 0;
	res = ft_calloc(size, 1);
	if (!res)
	{
		free(item->string);
		return (NULL);
	}
	ft_memset(res, filler, size - 1);
	return (ft_strjoin_free_both(res, item->string));
}

void	handle_max(t_format *item)
{
	char	*res;
	char	*temp;

	res = 0;
	res = ft_calloc(item->max + 1, 1);
	if (!res)
	{
		free(item->string);
		return ;
	}
	ft_strlcpy(res, item->string, item->max + 1);
	temp = item->string;
	item->string = res;
	free(temp);
}
