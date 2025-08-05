/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvanaut < alvanaut@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 13:07:36 by alvanaut          #+#    #+#             */
/*   Updated: 2025/08/05 13:09:59 by alvanaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	handle_operator(const char *line, char **tokens, int *count, int i)
{
	if (!line || !tokens || !count)
		return (-1);
	return (create_operator_token(line, tokens, count, i));
}

int	skip_quoted_section(const char *line, int i)
{
	char	quote_char;

	quote_char = line[i];
	i++;
	while (line[i] && line[i] != quote_char)
		i++;
	if (!line[i])
		return (-1);
	return (i + 1);
}

int	find_word_end(const char *line, int start)
{
	int	i;
	int	next;

	i = start;
	while (line[i] && !ft_isspace(line[i]) && !is_operator_sign(line[i]))
	{
		if (line[i] == '\'' || line[i] == '"')
		{
			next = skip_quoted_section(line, i);
			if (next == -1)
				return (-1);
			i = next;
		}
		else
			i++;
	}
	return (i);
}

int	handle_word(const char *line, char **tokens, int *count, int i)
{
	int		end;
	char	*word;

	if (!line || !tokens || !count)
		return (-1);
	end = find_word_end(line, i);
	if (end == -1)
	{
		printf("minishell: syntax error: unclosed quote\n");
		return (-1);
	}
	if (end == i)
		return (end);
	word = ft_substr(line, i, end - i);
	if (!word || !add_token(tokens, count, word))
	{
		free(word);
		return (-1);
	}
	return (end);
}
