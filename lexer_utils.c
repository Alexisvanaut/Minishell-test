/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvanaut < alvanaut@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 12:22:47 by alvanaut          #+#    #+#             */
/*   Updated: 2025/08/05 14:03:03 by alvanaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_operator_sign(char c)
{
	return (c == '|' || c == '&' || c == '<' || c == '>' || c == '(' || c == ')'
		|| c == ';');
}

int	is_separator(const char *s)
{
	if (!s)
		return (0);
    return ((ft_strcmp(s, "|") | ft_strcmp(s, "&") | ft_strcmp(s, "<") |
                ft_strcmp(s, ">") | ft_strcmp(s, "(") | ft_strcmp(s, ")") |
                ft_strcmp(s, "||") | ft_strcmp(s, "&&") | ft_strcmp(s, "<<") |
                ft_strcmp(s, ">>")  ) == 0);
	return (0);
}

int	add_token(char **tokens, int *count, char *token)
{
	if (!tokens || !count || *count >= MAX_TOKENS - 1)
		return (0);
	if (!token)
		return (0);
	tokens[(*count)++] = token;
	return (1);
}

char	*in_quote(const char *str)
{
	int		i;
	char	quote;

	if (!str || (*str != '\'' && *str != '"'))
		return (NULL);
	quote = *str;
	i = 1;
	while (str[i])
	{
		if (str[i] == quote)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r');
}
