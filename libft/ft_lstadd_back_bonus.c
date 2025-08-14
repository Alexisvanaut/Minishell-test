/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucorrei <lucorrei@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:26:38 by lucorrei          #+#    #+#             */
/*   Updated: 2025/04/17 14:18:20 by lucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!new || !lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}
/*
static void _helper(char *s)
{
	ft_putendl_fd(s, 1);
}

int	main(void)
{
	t_list *l1;
	t_list *l2;

	ft_lstadd_back(&l, ft_lstnew("1"));
	ft_lstadd_back(&l, ft_lstnew("2"));
	ft_lstadd_back(&l2, ft_lstnew("3"));
	ft_lstadd_back(&l2, ft_lstnew("4"));
	ft_lstadd_back(&l, l2);
	ft_lstiter(l, _helper);
	return (0);
}*/
