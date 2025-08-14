/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucorrei <lucorrei@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:26:38 by lucorrei          #+#    #+#             */
/*   Updated: 2025/04/16 16:20:41 by lucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = 0;
	new_node = ft_calloc(1, sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->next = NULL;
	new_node->content = content;
	return (new_node);
}
/*
int	main(int argc, char **argv)
{
	t_list *new;

	if (argc != 2)
	{
		write(1, "please provide a single string as input\n", 40);
		return (1);
	}
	new = ft_lstnew(argv[1]);
	write(1, "new->content =", 14);
	write(1, new->content, ft_strlen(new->content));
	write(1, "\n", 1);
	return (0);
}*/
