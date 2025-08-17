#include "minishell.h"

char *get_env_value(char *key, char **envp)
{
    int i;
    size_t len;

    if (!key || !envp)
        return (NULL);
    len = ft_strlen(key);
    i = 0;
    while (envp[i])
    {
        if (ft_strncmp(envp[i], key, len) == 0 && envp[i][len] == '=')
            return (ft_strdup(envp[i] + len + 1)); // valeur après '='
        i++;
    }
    return (ft_strdup("")); // si pas trouvé -> vide
}

static char *expand_status(char *res, int *i, int last_status)
{
	char *status;

	status = ft_itoa(last_status);
	res = ft_strjoin_free_both(res, status);
	free(status);
	(*i)++;
	return (res);
}

static char	*expand_env_var(char *res, char *value, int *i, char **envp)
{
	int		start;
	char	*key;
	char	*val;

	start = *i;
	while (ft_isalnum(value[*i]) || value[*i] == '_')
		(*i)++;
	key = ft_substr(value, start, *i - start);
	val = get_env_value(key, envp);
	res = ft_strjoin_free_both(res, val);
	free(key);
	free(val);
	return (res);
}

static char	*append_char(char *res, char c)
{
	char	buf[2];

	buf[0] = c;
	buf[1] = '\0';
	return (ft_strjoin_free_both(res, buf));
}

char	*expand_variables(char *value, char **envp, int last_status, t_quote_type quote)
{
	char	*res;
	int		i;

	if (!value)
		return (NULL);
	if (quote == Q_SIMPLE)
		return (ft_strdup(value));
	res = ft_strdup("");
	i = 0;
	while (value[i])
	{
		if (value[i] == '$')
		{
			i++;
			if (value[i] == '?')
				res = expand_status(res, &i, last_status);
			else
				res = expand_env_var(res, value, &i, envp);
		}
		else
			res = append_char(res, value[i++]);
	}
	return (res);
}

void	print_tokens(t_token *tokens)
{
	t_token *tmp = tokens;
	while (tmp)
	{
		printf("value: [%s], type: %d, quote: %d\n",
			tmp->value, tmp->type, tmp->quote);
		tmp = tmp->next;
	}
}


//int	main(void)
//{
//	char		*line;
//	t_lexeme	*lex;
//	t_token		*tokens;
//	t_token		*tmp;
//	char		*envp[] = {"USER=42School", "HOME=/home/user", NULL};
//	int			last_status = 0;
//
//	while (1)
//	{
//		line = read_line(); // ta fonction perso
//		if (!line)
//			break ;
//
//		lex = lexer(line);
//		free(line);
//		if (!lex)
//			continue ;
//
//		tokens = lexer_to_token(lex);
//		free_lexemes(lex);
//		if (!tokens)
//			continue ;
//
//		tmp = tokens;
//		while (tmp)
//		{
//			char *expanded = expand_variables(tmp->value, envp, last_status, tmp->quote);
//			free(tmp->value);
//			tmp->value = expanded;
//			tmp = tmp->next;
//		}
//
//		print_tokens(tokens);
//		free_token(tokens);
//	}
//	return (0);
//}
