/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucorrei <lucorrei@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:26:39 by lucorrei          #+#    #+#             */
/*   Updated: 2025/05/11 17:47:23 by lucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	free_format(void *to_free)
{
	free(((t_format *)to_free)->string);
	free(to_free);
}
// void	iter_to_stdout(void *a)
// {
// 	char		*str;
//
// 	str = ((t_format *)a)->string;
// 	ft_putstr_fd(str, 1);
// }
//
// int	count_printed(t_list *lst)
// {
// 	t_format	*tmp;
// 	int			count;
//
// 	count = 0;
// 	tmp = 0;
// 	while (lst)
// 	{
// 		tmp = lst->content;
// 		count += ft_strlen(tmp->string);
// 		lst = lst->next;
// 	}
// 	return (count);
// }

int	check_and_print(t_list *lst)
{
	int			res;
	t_list		*first;
	t_format	*tmp;

	first = lst;
	res = 0;
	while (lst)
	{
		tmp = (t_format *) lst->content;
		if (!tmp || !tmp->string || FORMAT_ERROR & tmp->formatting)
		{
			ft_lstclear(&first, &free_format);
			return (-1);
		}
		ft_putstr_fd(tmp->string, 1);
		res += ft_strlen(tmp->string);
		if (IS_CHAR & tmp->formatting && !ft_memcmp(tmp->string, "\0\0", 2))
		{
			ft_putchar_fd(0, 1);
			res += 1;
		}
		lst = lst->next;
	}
	ft_lstclear(&first, &free_format);
	return (res);
}
