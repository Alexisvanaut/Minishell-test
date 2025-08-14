/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucorrei <lucorrei@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 22:43:59 by lucorrei          #+#    #+#             */
/*   Updated: 2025/04/17 13:33:49 by lucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*start;
	t_list	*elem;
	void	*new_content;

	if (!f || !lst || !del)
		return (NULL);
	start = NULL;
	while (lst)
	{
		elem = 0;
		new_content = (*f)(lst->content);
		elem = ft_lstnew(new_content);
		if (!elem)
		{
			(*del)(new_content);
			ft_lstclear(&start, del);
			return (NULL);
		}
		ft_lstadd_back(&start, elem);
		lst = lst->next;
	}
	return (start);
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
