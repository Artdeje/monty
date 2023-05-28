#include "monty.h"

/**
 * create_node - Creates a new stack node.
 * @value: The value to store in the new node.
 *
 * Return: A pointer to the newly created node.
 */
stack_t *create_node(int value)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = NULL;

	return (new_node);
}
