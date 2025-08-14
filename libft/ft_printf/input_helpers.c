/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucorrei <lucorrei@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 15:36:06 by lucorrei          #+#    #+#             */
/*   Updated: 2025/05/13 15:36:12 by lucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	handle_pointers(va_list *args, t_format *to_add)
{
	size_t	ptr;

	ptr = va_arg(*args, size_t);
	if (ptr)
	{
		to_add->string = ft_ultoa_16(ptr);
		to_add->formatting |= HEX_SIGNAL;
	}
	else
		to_add->string = ft_strdup("(nil)");
}

void	save_regular_str(char **s, char **cursor, t_list **lst)
{
	char		*temp;
	t_format	*regular;

	temp = ft_calloc(*cursor - *s + 1, 1);
	ft_strlcpy(temp, *s, *cursor - *s + 1);
	regular = ft_calloc(1, sizeof(t_format));
	regular->string = temp;
	regular->max = -1UL;
	ft_lstadd_back(lst, ft_lstnew(regular));
	*s = *cursor;
}

char	chr_in_str(char c, char *str)
{
	while (str && *str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

void	parse_flags(char cursor, t_format *format)
{
	if (cursor == '+')
		format->formatting |= NUMBER_PLUS;
	if (cursor == ' ')
		format->formatting |= NUMBER_SPACE;
	if (cursor == '#')
		format->formatting |= HEX_SIGNAL;
	if (cursor == '-')
		format->formatting |= ALIGN_LEFT;
	if (cursor == '0')
		format->formatting |= ZERO_PAD;
}

void	handle_ints(char type, t_format *to_add, int integer)
{
	if (type == 'd' || type == 'i')
	{
		if (integer < 0)
		{
			integer *= -1;
			if (integer != INT_MIN_FTPF)
				to_add->formatting |= IS_NEG;
		}
		to_add->string = ft_itoa(integer);
	}
	else
		to_add->string = ft_itoa_16(integer);
	if (type == 'X')
		to_add->formatting |= TO_UPPER;
}
