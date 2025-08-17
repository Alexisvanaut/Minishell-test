#include "../minishell.h"

void	free_cmd(t_command *cmd)
{
	int i;
	
	if (!cmd)
		return ;
	i = 0;
	while (cmd->args[i])
	{
		free(cmd->args[i]);
		i++;
	}
	if (cmd->path)
		free(cmd->path);
	free(cmd);
}	

int		count_args(char **args)
{
	int i;

	i = 0;
	if (!args)
		return (0);
	while (args[i])
		i++;
	return (i);
}


t_command *init_cmd(char *path, char **args)
{
	t_command *cmd;
	int i;

	cmd = malloc(sizeof(t_command));
	if (!cmd)
		return (NULL);
	cmd->path = ft_strdup(path);
	if (!cmd->path)
		return (free_cmd(cmd), NULL);
	i = 0;
	cmd->args = malloc(sizeof(char *) * (count_args(args) + 1));
	if (!cmd->args)
		return (NULL);
	while (args[i])
	{
		cmd->args[i] = ft_strdup(args[i]);
		if (!cmd->args[i])
			return (free_cmd(cmd), NULL);
		i++;
	}
	cmd->args[i] = NULL;
	return (cmd);
}



t_ast *init_ast(t_node_type type, t_command *command, char *filename, int fd_in, int fd_out)
{
	t_ast *ast;

	ast = malloc(sizeof(t_ast));
	if (!ast)
		return (NULL);
	ast->command = command;
	if (!ast->command)
		return (free_ast(ast), NULL);
	ast->fd_in = fd_in;
	ast->fd_out = fd_out;
	if (!filename)
		return (NULL);
	ast->filename = ft_strdup(filename);
	if (!ast->filename)
		return (free_ast(ast) ,NULL);
	ast->type = type;
	ast->left = NULL;
	ast->right = NULL;
	return (ast);
}

void	free_ast(t_ast *ast)
{
	if (!ast)
		return ;
	if (ast->command)
		free_cmd(ast->command);
	if (ast->filename)
		free(ast->filename);
	if (ast->left)
		free_ast(ast->left);
	if (ast->right)
		free_ast(ast->right);
}

// Changer les tokens en ast
// 1. Mette le type en node -> builtins
// 2. Trouver ordre de prioriter
// 3. Creer le tree   |
// 				word	cmd


int		is_builtin(char *value)
{
	if (!value)
		return (0);
	if (ft_strncmp(value, "echo", 4) == 0 || ft_strncmp(value, "cd", 2) == 0 ||
		ft_strncmp(value, "pwd", 3) == 0 || ft_strncmp(value, "export", 6) == 0 ||
		ft_strncmp(value, "unset", 5) == 0 || ft_strncmp(value, "env", 4) == 0 ||
		ft_strncmp(value, "exit", 4) == 0)
	 	return (1);
	return (0);
}

t_node_type token_to_node_type(t_token *token)
{
	if (!token)
		return (NODE_CMD);
	char *value;

	value = token->value;
	if (ft_strcmp(value, "||") == 0)
		return (NODE_OR);
	else if (ft_strcmp(value, "&&") == 0)
		return (NODE_AND);
	else if (ft_strcmp(value, ">>") == 0)
		return (NODE_APPEND);
	else if (ft_strcmp(value, "<<") == 0)
		return (NODE_HEREDOC);
	else if (ft_strcmp(value, "|") == 0)
		return (NODE_PIPE);
	else if (ft_strcmp(value, ">") == 0)
		return (NODE_OUT);
	else if (ft_strcmp(value, "<") == 0)
		return (NODE_IN);
	else if (is_builtin(value))
			return (NODE_BUILTIN);
	else
		return (NODE_CMD);
}







