#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * tokenizer - Tokenizes a line of input into individual tokens
 * @line: The line of input to be tokenized
 *
 * Return: A pointer to an array of tokens
 */
char **tokenizer(char *line)
{
	char **tokens = NULL;
	char *token = NULL;
	int i = 0;
	const char *delimiters = " \t\n";

	tokens = malloc(sizeof(char *) * TOKEN_BUFFER_SIZE);
	if (tokens == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, delimiters);
	while (token != NULL)
	{
		tokens[i++] = token;

		if (i >= TOKEN_BUFFER_SIZE)
		{
			tokens = realloc(tokens, sizeof(char *) * (TOKEN_BUFFER_SIZE * 2));
			if (tokens == NULL)
			{
				fprintf(stderr, "Error: realloc failed\n");
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, delimiters);
	}

	tokens[i] = NULL;

	return (tokens);
}
