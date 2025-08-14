/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucorrei <lucorrei@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:54:40 by lucorrei          #+#    #+#             */
/*   Updated: 2025/05/10 18:10:42 by lucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	format_string(void *ptr)
{
	t_format	*to_modify;
	short		formatting;
	char		*to_prepend;

	to_modify = (t_format *) ptr;
	formatting = to_modify->formatting;
	to_prepend = prepend(formatting);
	if (to_prepend)
	{
		to_modify->string = ft_strjoin_free_both(to_prepend, to_modify->string);
	}
	if (TO_UPPER & formatting)
	{
		ft_striteri(to_modify->string, &ft_toupper_iter);
	}
}

void	handle_width(void *fmt_ptr)
{
	short		fmt;
	t_format	*item;

	item = (t_format *)fmt_ptr;
	if (!item || !item->string)
		return ;
	fmt = item->formatting;
	if (item->max < ft_strlen(item->string))
		handle_max(item);
	if (!(fmt & NEEDS_ALIGN))
		return ;
	else if (fmt & ALIGN_LEFT)
		item->string = align_left(item);
	else
		item->string = align_right(item);
}
