/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucorrei <lucorrei@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:26:38 by lucorrei          #+#    #+#             */
/*   Updated: 2025/04/15 22:38:13 by lucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		res;
	t_list	*cursor;

	if (lst == NULL)
		return (0);
	res = 1;
	cursor = lst;
	while (cursor->next != NULL)
	{
		res++;
		cursor = cursor->next;
	}
	return (res);
}
/*
int	main(int argc, char **argv)
{
	t_list *new;
	t_list *old;

	if (argc == 1)
	{
		write(1, "please provide at least single string as input\n", 47);
		return (1);
	}
	new = ft_lstnew(argv[--argc]);
	while (argc > 1)
	{
		argc--;
		old = new;
		new = ft_lstnew(argv[argc]);
		ft_lstadd_front(&old, new);
	}
	ft_putendl_fd("list size", 1);
	ft_putnbr_fd(ft_lstsize(new), 1);
	return (0);
} */
