#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Entry point of the Monty interpreter.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line arguments.
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL;
	size_t line_len = 0;
	stack_t *stack = NULL;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&line, &line_len, file) != -1)
	{
		line_number++;
		data = strtok(line, " \t\n");

		if (data != NULL && strcmp(data, "push") == 0)
		{
			data = strtok(NULL, " \t\n");
			if (!is_integer(data))
			{
				fprintf(stderr, "L%u: usage: push integer\n", line_number);
				free_stack(stack);
				free(line);
				fclose(file);
				exit(EXIT_FAILURE);
			}
			push(&stack, atoi(data));
		}
		else if (data != NULL)
		{
			if (strcmp(data, "stack") == 0)
				stack_mode(&stack);
			else if (strcmp(data, "queue") == 0)
				queue_mode(&stack);
			else if (strcmp(data, "pop") == 0)
				pop(&stack, line_number);
			else if (strcmp(data, "pall") == 0)
				pall(stack);
			else if (strcmp(data, "pint") == 0)
				pint(stack, line_number);
			else if (strcmp(data, "swap") == 0)
				swap(&stack, line_number);
			else if (strcmp(data, "add") == 0)
				add(&stack, line_number);
			else if (strcmp(data, "nop") == 0)
				nop(&stack, line_number);
			else
			{
				fprintf(stderr, "L%u: unknown instruction %s\n", line_number, data);
				free_stack(stack);
				free(line);
				fclose(file);
				exit(EXIT_FAILURE);
			}
		}
	}

	free_stack(stack);
	free(line);
	fclose(file);

	return (0);
}
