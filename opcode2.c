#include "monty.h"

/**
 * push - Pushes an element to the stack.
 * @stack: Double pointer to the head of the stack.
 * @value: The value to be pushed.
**/
void push(stack_t **stack, int value)
{
	stack_t *new_node = create_node(value);

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->next = *stack;
	*stack = new_node;
}

/**
 * create_node - Creates a new node for the stack.
 * @value: The value to be stored in the node.
 *
 * Return: A pointer to the newly created node, or NULL on failure.
**/
stack_t *create_node(int value)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = value;
	new_node->next = NULL;

	return (new_node);
}

