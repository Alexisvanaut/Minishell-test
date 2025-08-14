/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucorrei <lucorrei@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:26:38 by lucorrei          #+#    #+#             */
/*   Updated: 2025/04/17 12:38:11 by lucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next;

	if (!del || !*lst || !lst)
		return ;
	while (*lst)
	{
		next = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = next;
	}
	*lst = NULL;
}
/*
int	main(int argc, char ** argv)
{
	t_list *new;
	t_list *old;

	if (argc == 1)
	{
		write(1, "please provide at least single string as input\n", 47);
		return (1);
	}
	old = 0;
	while (--argc >= 1)
	{
		new = ft_lstnew(ft_strdup(argv[argc]));
		ft_lstadd_front(&old, new);
	}
	ft_putendl_fd("using free(x) as del", 1);
	ft_lstclear(&old, &free);
	ft_putendl_fd("successfully freed!", 1);
	return (0);
}*/
