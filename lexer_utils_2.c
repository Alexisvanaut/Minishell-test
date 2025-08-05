/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvanaut < alvanaut@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 12:24:11 by alvanaut          #+#    #+#             */
/*   Updated: 2025/08/05 13:46:14 by alvanaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_tokens(char **tokens, int count)
{
	int	i;

	if (!tokens)
		return ;
	i = 0;
	while (i < count)
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

int	find_quote_end(const char *line, int start, char quote_char)
{
	int	i;

	i = start + 1;
	while (line[i] && line[i] != quote_char)
		i++;
	if (!line[i])
		return (-1);
	return (i);
}

int	handle_quotes(const char *line, char **tokens, int *count, int i)
{
	char	quote_char;
	int		end;
	char	*content;

	if (!line || !tokens || !count)
		return (-1);
	quote_char = line[i];
	end = find_quote_end(line, i, quote_char);
	if (end == -1)
	{
		printf("minishell: syntax error: unclosed quote '%c'\n", quote_char);
		return (-1);
	}
	content = ft_substr(line, i + 1, end - (i + 1));
	if (!content || !add_token(tokens, count, content))
	{
		free(content);
		return (-1);
	}
	return (end + 1);
}

int	is_double_operator(const char *line, int i)
{
	if (!line[i + 1] || line[i] != line[i + 1])
		return (0);
	if ((line[i] == '>' && line[i + 1] == '>') || (line[i] == '<' && line[i
			+ 1] == '<') || (line[i] == '&' && line[i + 1] == '&')
		|| (line[i] == '|' && line[i + 1] == '|'))
		return (1);
	return (0);
}

int	create_operator_token(const char *line, char **tokens, int *count, int i)
{
	char	*op_token;
	int		op_len;

	if (is_double_operator(line, i))
		op_len = 2;
	else if (ft_strchr("><|&();", line[i]))
		op_len = 1;
	else
	{
		printf("minishell: syntax error near '%c'\n", line[i]);
		return (-1);
	}
	op_token = ft_substr(line, i, op_len);
	if (!op_token || !add_token(tokens, count, op_token))
	{
		free(op_token);
		return (-1);
	}
	return (i + op_len);
}
