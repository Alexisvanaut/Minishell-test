/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucorrei <lucorrei@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:26:38 by lucorrei          #+#    #+#             */
/*   Updated: 2025/04/16 10:24:54 by lucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}

/*
char	helper(unsigned int i, char c)
{
	(void) i;
	return ft_toupper(c);
}
void	test_fn(void *str)
{
	ft_putendl_fd(ft_strmapi((char *)str, &helper), 1);
}

int	main(int argc, char **argv)
{
	t_list *new;
	t_list *old;

	if (argc == 1)
	{
		ft_putendl_fd("please provide at least single string as input", 1);
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
	ft_putendl_fd("function is ft_putendl(ft_strmap(ft_toupper))", 1);
	ft_lstiter(new, &test_fn);
	return (0);
}*/
