#include "../minishell.h"
#include <string.h>


void	free_tokens_safe(char **tokens)
{
	int	i;

	if (!tokens)
		return ;
	i = 0;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

void	test_with_progress(const char *input, const char *test_name)
{
	char	**tokens;
	int		i;

	printf("\n🧪 Test: %s\n", test_name);
	printf("Input: \"%s\"\n", input);
	printf("Processing");
	fflush(stdout);
	
	// Simulation de progression pour voir si ça bloque
	for (i = 0; i < 3; i++)
	{
		printf(".");
		fflush(stdout);
		usleep(100000); // 0.1 seconde
	}
	
	tokens = split_line_smart(input);
	
	if (!tokens)
	{
		printf(" ❌ NULL\n");
		return ;
	}
	
	printf(" ✅\n");
	
	// Affichage sécurisé avec limite
	i = 0;
	while (tokens[i] && i < 20)
	{
		printf("  [%d]: \"%s\"\n", i, tokens[i]);
		i++;
	}
	
	if (i >= 20)
		printf("  ⚠️ Trop de tokens (>20), arrêt sécuritaire\n");
	else if (i == 0)
		printf("  📝 Aucun token généré\n");
	else
		printf("  📊 Total: %d tokens\n", i);
	
	free_tokens_safe(tokens);
}

int	main(void)
{
	char	input[1024];
	int		test_count;
	
	printf("🚀 Testeur en continu du lexer minishell\n");
	printf("========================================\n");
	printf("Entrez vos commandes de test (ou 'quit' pour sortir)\n");
	printf("Commandes spéciales:\n");
	printf("  'auto'  - Lance une série de tests automatiques\n");
	printf("  'basic' - Tests de base rapides\n");
	printf("  'stress'- Test intensif\n");
	printf("  'quit'  - Quitter\n\n");
	
	test_count = 0;
	
	while (1)
	{
		printf("minishell_test[%d]> ", test_count);
		fflush(stdout);
		
		if (!fgets(input, sizeof(input), stdin))
			break ;
		
		// Enlever le \n
		input[strcspn(input, "\n")] = 0;
		
		if (strcmp(input, "quit") == 0)
			break ;
		
		if (strcmp(input, "auto") == 0)
		{
			printf("\n🤖 Tests automatiques:\n");
			test_with_progress("ls -la", "Commande simple");
			test_with_progress("echo 'hello'", "Guillemets simples");
			test_with_progress("echo \"world\"", "Guillemets doubles");
			test_with_progress("cat | grep test", "Pipe");
			test_with_progress("cmd1 && cmd2", "AND");
			test_with_progress("cmd1 || cmd2", "OR");
			test_with_progress("echo > file", "Redirection");
			test_with_progress("", "Ligne vide");
			test_with_progress("   ", "Espaces seulement");
			continue ;
		}
		
		if (strcmp(input, "basic") == 0)
		{
			printf("\n⚡ Tests de base:\n");
			test_with_progress("hello", "Un mot");
			test_with_progress("hello world", "Deux mots");
			test_with_progress("a|b", "Pipe simple");
			continue ;
		}
		
		if (strcmp(input, "stress") == 0)
		{
			printf("\n💪 Test de stress:\n");
			for (int i = 0; i < 100; i++)
			{
				printf("\rTest %d/100", i + 1);
				fflush(stdout);
				
				char **tokens = split_line_smart("echo hello");
				if (tokens)
				{
					free_tokens_safe(tokens);
				}
				else
				{
					printf("\n❌ Échec au test %d\n", i + 1);
					break ;
				}
			}
			printf("\n✅ Stress test terminé!\n");
			continue ;
		}
		
		// Test de l'input utilisateur
		test_with_progress(input, "Input utilisateur");
		test_count++;
	}
	
	printf("\n👋 Tests terminés! Total: %d tests effectués.\n", test_count);
	return (0);
}
