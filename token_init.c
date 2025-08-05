/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvanaut < alvanaut@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 15:51:42 by alvanaut          #+#    #+#             */
/*   Updated: 2025/08/05 12:20:46 by alvanaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_token	*init_token(char *value, t_token_type type)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	if (!value)
		return (NULL);
	token->value = ft_strdup(value);
	token->type = type;
	token->next = NULL;
	return (token);
}

void	free_token(t_token *token)
{
	if (!token)
		return ;
	free(token->value);
	free(token);
}
