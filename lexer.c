/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvanaut < alvanaut@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 12:13:45 by alvanaut          #+#    #+#             */
/*   Updated: 2025/08/05 14:02:17 by alvanaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	is_standalone_quote(const char *line, int i)
{
	if (line[i] != '\'' && line[i] != '"')
		return (0);
	if (i == 0 || ft_isspace(line[i - 1]) || is_operator_sign(line[i - 1]))
		return (1);
	return (0);
}

static int	process_token(const char *line, char **tokens, int *count, int i)
{
	while (ft_isspace(line[i]))
		i++;
	if (!line[i])
		return (-1);
	if (is_standalone_quote(line, i))
		return (handle_quotes(line, tokens, count, i));
	else if (is_separator(&line[i]))
		return (handle_operator(line, tokens, count, i));
	else
		return (handle_word(line, tokens, count, i));
}

static int	validate_tokens(char **tokens, int count)
{
	int	i;

	if (!tokens || count == 0)
		return (1);
	i = 0;
	while (i < count)
	{
		if (is_separator(&tokens[i][0]))
		{
			if (i == 0 || i == count - 1)
			{
				printf("minishell: syntax error near '%s'\n", tokens[i]);
				return (0);
			}
		}
		i++;
	}
	return (1);
}

static int	tokenize_line(const char *line, char **tokens, int *count)
{
	int	i;
	int	next;

	i = 0;
	*count = 0;
	while (line[i] && *count < MAX_TOKENS - 1)
	{
		next = process_token(line, tokens, count, i);
		if (next == -1)
		{
			if (line[i])
				return (0);
			break ;
		}
		i = next;
	}
	if (*count >= MAX_TOKENS - 1)
	{
		printf("minishell: command line too complex\n");
		return (0);
	}
	return (1);
}

char	**split_line_smart(const char *line)
{
	char	**tokens;
	int		count;

	if (!line)
		return (NULL);
	tokens = ft_calloc(MAX_TOKENS, sizeof(char *));
	if (!tokens)
		return (NULL);
	if (!tokenize_line(line, tokens, &count))
	{
		free_tokens(tokens, count);
		return (NULL);
	}
	if (!validate_tokens(tokens, count))
	{
		free_tokens(tokens, count);
		return (NULL);
	}
	tokens[count] = NULL;
	return (tokens);
}
