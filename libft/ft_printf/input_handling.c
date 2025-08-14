/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucorrei <lucorrei@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:53:11 by lucorrei          #+#    #+#             */
/*   Updated: 2025/05/12 12:48:31 by lucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	make_format(char **cursor, t_list **lst)
{
	t_format	*format;

	format = ft_calloc(1, sizeof(t_format));
	ft_lstadd_back(lst, ft_lstnew(format));
	if (**cursor == '%')
		return ;
	while (chr_in_str(**cursor, FLAGS))
	{
		parse_flags(**cursor, format);
		(*cursor)++;
	}
	format->min = (size_t) ft_atoi_consume(cursor);
	if (**cursor == '.')
	{
		(*cursor)++;
		format->max = (size_t) ft_atoi_consume(cursor);
	}
	else
		format->max = -1UL;
	if (format->min)
		format->formatting |= NEEDS_ALIGN;
}

void	handle_types2(char **cursor, va_list *args, t_format *to_add)
{
	char	*temp;

	if (**cursor == 'u')
		to_add->string = ft_uitoa(va_arg(*args, int));
	else if (**cursor == 's')
	{
		temp = va_arg(*args, char *);
		if (!temp)
			to_add->string = ft_strdup("(null)");
		else
			to_add->string = ft_strdup(temp);
	}
	else if (**cursor == 'c')
	{
		to_add->string = ft_chr_to_str(va_arg(*args, int));
		to_add->formatting |= IS_CHAR;
	}
	else
	{
		to_add->formatting |= FORMAT_ERROR;
		(*cursor)--;
	}
}

void	handle_types1(char **cursor, t_list **lst, va_list *args)
{
	t_format	*to_add;
	int			integer;

	to_add = ft_lstlast(*lst)->content;
	if (**cursor == '%')
	{
		to_add->string = ft_strdup("%");
		to_add->max = -1UL;
	}
	else if (chr_in_str(**cursor, "xXdi"))
	{
		integer = va_arg(*args, int);
		handle_ints(**cursor, to_add, integer);
	}
	else if (**cursor == 'p')
		handle_pointers(args, to_add);
	else
		handle_types2(cursor, args, to_add);
}

static void	handle_percent(char **s, char **cursor, va_list *args, t_list **lst)
{
	save_regular_str(s, cursor, lst);
	(*cursor)++;
	make_format(cursor, lst);
	handle_types1(cursor, lst, args);
	*s = (*cursor) + 1;
}

int	ft_printf(const char *s, ...)
{
	char		*cursor;
	t_list		*lst;
	va_list		args;

	cursor = (char *)s;
	va_start(args, s);
	lst = 0;
	while (1)
	{
		if (*cursor == '%')
			handle_percent((char **)&s, &cursor, &args, &lst);
		if (!*cursor)
		{
			save_regular_str((char **)&s, &cursor, &lst);
			break ;
		}
		cursor++;
	}
	va_end(args);
	ft_lstiter(lst, &format_string);
	ft_lstiter(lst, &handle_width);
	return (check_and_print(lst));
}
