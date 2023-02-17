#include "main.h"
#define MAX_TOKENS 100
#define TOKEN_DELIM " "
/**
 * get_token - splits string into individual elements
 * @str: pointer to string
 * Return: pointer to new char array
 */
char **get_token(char *str)
{
	int num_tokens = 0;
	char **tokens, *token;
	
	tokens = malloc(sizeof(char*) * MAX_TOKENS);
	if (str == NULL)
		str = " ";
	if (tokens == NULL)
	{
		perror("Error allocating memory for tokens");
		exit(EXIT_FAILURE);
	}
	token = strtok(str, " ");
	while (token != NULL)
	{
		if (num_tokens >= MAX_TOKENS)
		{
			perror("Too many tokens");
			exit(EXIT_FAILURE);
		}
		tokens[num_tokens] = token;
		num_tokens++;
		token = strtok(NULL, TOKEN_DELIM);
	}
	tokens[num_tokens] = NULL;
	return (tokens);
}
