#include "../minishell.h"

static char *read_line(void)
{
	char *line;

	line = readline("$Minishell ");
	if (!line)
		return (NULL);
	if (ft_strcmp(line, "exit") == 0)
		return (free(line), NULL);
	add_history(line);
	return (line);
}

static char *handle_separator(char *line, int *i)
{
	if (!line)
		return (NULL);
	if (ft_strncmp(line, "||", 2) == 0)
		return (*i += 2, ft_substr(line, 0, 2));
	if (ft_strncmp(line, "|", 1) == 0)
		return (*i += 1, ft_substr(line, 0, 1));
	if (ft_strncmp(line, "&&", 2) == 0)
		return (*i += 2, ft_substr(line, 0, 2));
	if (ft_strncmp(line, "&", 1) == 0)
		return (*i += 1, ft_substr(line, 0, 1));
	if (ft_strncmp(line, ">>", 2) == 0)
		return (*i += 2, ft_substr(line, 0, 2));
	if (ft_strncmp(line, ">", 1) == 0)
		return (*i += 1, ft_substr(line, 0, 1));
	if (ft_strncmp(line, "<<", 2) == 0)
		return (*i += 2, ft_substr(line, 0, 2));
	if (ft_strncmp(line, "<", 1) == 0)
		return (*i += 1, ft_substr(line, 0, 1));
	if (ft_strncmp(line, "(", 1) == 0)
		return (*i += 1, ft_substr(line, 0, 1));
	if (ft_strncmp(line, ")", 1) == 0)
		return (*i += 1, ft_substr(line, 0, 1));
	if (ft_strncmp(line, ";", 1) == 0)
		return (*i += 1, ft_substr(line, 0, 1));
	return (NULL);
}

static char	*handle_quote(char *line, int *i)
{
	char quote;
	int	index;

	if (!line)
		return (NULL);
	quote = line[0];
	if (quote != '\'' && quote != '"')
		  return (NULL);
	index = 1;
	while (line[index] && line[index] != quote)
		index++;
	if (!line[index])
		return (printf("Syntax error: unclosed quote\n"), NULL);
	return (*i += index + 1, ft_substr(line, 1,  index - 1));
}

static int		is_separator(char *line)
{
	if (!line)
		return (0);
	if (ft_strncmp(line, "||", 2) == 0 || ft_strncmp(line, "&&", 2) == 0 || ft_strncmp(line, ">>", 2) == 0 ||
		ft_strncmp(line, "<<", 2) == 0 ) 
		return (1);
	if(ft_strncmp(line, ")", 1) == 0 || ft_strncmp(line, "(", 1) == 0 || ft_strncmp(line, "|", 1) == 0 ||
		ft_strncmp(line, ">", 1) == 0 || ft_strncmp(line, "<", 1) == 0 || ft_strncmp(line, ";", 1) == 0 || 
		ft_strncmp(line, "&", 1) == 0)
		return (1);
	if (line[0] == '\'' || line[0] == '"')
		return (2);
	return (0);
}

static char	*handle_word(char *line, int *i)
{
	int index;

	index = 0;
	while (line[index] && !is_separator(&line[index]))
	{
		if (line[index] == '\\' && line[index + 1])
	  		index++;
		index++;
	}
	if (!line[index])
		return (*i += index, ft_substr(line, 0, index));
	return (*i += index, ft_substr(line, 0, index - 1));
}

void	skip_spaces(char *line, int *i)
{
	while (line[*i] == '\t' || line[*i] == ' ')
		(*i)++;
}

char	**add_token(char **tokens, char *token)
{
	int count;
	char **new_tokens;
	int i;

	count = 0;
	if (!token)
		return (NULL);
	if (tokens)
	{
		while (tokens[count])
			count++;
	}
	new_tokens = malloc(sizeof(char *) * (count + 2));
	if (!new_tokens)
		return (NULL);
	i = 0;
	while (i < count)
	{
		new_tokens[i] = tokens[i];
		i++;
	}
	new_tokens[count] = ft_strdup(token);
	new_tokens[count + 1] = NULL;
	free(tokens);
	return (new_tokens);
}

char **lexer(char *line)
{
	char *token;
	char **tokens = NULL;
	int i;

	i = 0;
	while (line[i])
	{
		skip_spaces(line, &i);
		if (!line[i])
			break ;
		if (is_separator(&line[i]) == 1)
			token = handle_separator(&line[i], &i);
		else if (is_separator(&line[i]) == 2)
			token = handle_quote(&line[i], &i);
		else
			token = handle_word(&line[i], &i);
		add_token(tokens, token);
		free(token);
	}
	return (tokens);
}


//int main(void)
//{
//	char *line;
//    char **tokens = NULL;
//    char *token;
//    int i;
//
//    while ((line = read_line()))
//    {
//        i = 0;
//        tokens = NULL;
//
//        while (line[i])
//        {
//            skip_spaces(line, &i);
//            if (!line[i])
//                break;
//
//            if (is_separator(&line[i]) == 1)
//                token = handle_separator(&line[i], &i);
//            else if (is_separator(&line[i]) == 2)
//                token = handle_quote(&line[i], &i);
//            else
//                token = handle_word(&line[i], &i);
//
//            tokens = add_token(tokens, token);
//            free(token);
//        }
//
//        // Afficher les tokens
//        printf("=== TOKENS ===\n");
//        for (int j = 0; tokens && tokens[j]; j++)
//            printf("[%s]\n", tokens[j]);
//
//        // Libérer les tokens
//        if (tokens)
//        {
//            for (int j = 0; tokens[j]; j++)
//                free(tokens[j]);
//            free(tokens);
//        }
//        free(line);
//    }
//
//    return 0;
//}

